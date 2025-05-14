# Week 9: Flask and Web Applications

This document provides a comprehensive overview of Week 9 topics in CS50, covering Flask framework and web application development.

## Table of Contents
1. [Introduction to Flask](#introduction-to-flask)
2. [Routes and Views](#routes-and-views)
3. [Templates](#templates)
4. [Forms and User Input](#forms-and-user-input)
5. [Sessions and Cookies](#sessions-and-cookies)
6. [Database Integration](#database-integration)
7. [Application Structure](#application-structure)

## Introduction to Flask

### Basic Flask Application
```python
from flask import Flask, render_template, request, session
from flask_session import Session

app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    return render_template("index.html")

if __name__ == "__main__":
    app.run(debug=True)
```

### Project Structure
```
myapp/
├── static/
│   ├── styles.css
│   └── script.js
├── templates/
│   ├── layout.html
│   └── index.html
├── app.py
└── requirements.txt
```

## Routes and Views

### Basic Routing
```python
@app.route("/")
def index():
    return "Hello, World!"

@app.route("/greet/<name>")
def greet(name):
    return f"Hello, {name}!"

@app.route("/posts/<int:post_id>")
def show_post(post_id):
    return f"Post {post_id}"
```

### HTTP Methods
```python
@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        # Process login
        return redirect("/dashboard")
    return render_template("login.html")
```

## Templates

### Base Template (layout.html)
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>{% block title %}{% endblock %}</title>
    <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
</head>
<body>
    <nav>
        <a href="{{ url_for('index') }}">Home</a>
        <a href="{{ url_for('login') }}">Login</a>
    </nav>
    
    <main>
        {% block main %}{% endblock %}
    </main>
    
    <footer>
        &copy; 2024 My Flask App
    </footer>
</body>
</html>
```

### Child Template (index.html)
```html
{% extends "layout.html" %}

{% block title %}
    Home
{% endblock %}

{% block main %}
    <h1>Welcome to My App</h1>
    
    {% if session["user_id"] %}
        <p>Welcome back, {{ session["username"] }}!</p>
    {% else %}
        <p>Please log in to continue.</p>
    {% endif %}
{% endblock %}
```

## Forms and User Input

### HTML Form
```html
<form action="{{ url_for('register') }}" method="post">
    <div class="form-group">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required>
    </div>
    
    <div class="form-group">
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required>
    </div>
    
    <div class="form-group">
        <label for="confirmation">Confirm Password:</label>
        <input type="password" id="confirmation" name="confirmation" required>
    </div>
    
    <button type="submit">Register</button>
</form>
```

### Form Processing
```python
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        
        # Validate input
        if not username:
            return apology("must provide username")
        elif not password:
            return apology("must provide password")
        elif password != confirmation:
            return apology("passwords must match")
            
        # Hash password
        hash = generate_password_hash(password)
        
        try:
            # Insert user into database
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", 
                      username, hash)
            return redirect("/login")
        except:
            return apology("username already exists")
            
    return render_template("register.html")
```

## Sessions and Cookies

### Session Management
```python
@app.route("/login", methods=["GET", "POST"])
def login():
    # Forget any user_id
    session.clear()

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                         request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"],
            request.form.get("password")):
            return apology("invalid username and/or password")

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["username"] = rows[0]["username"]

        # Redirect user to home page
        return redirect("/")

    return render_template("login.html")
```

## Database Integration

### SQLite with Flask
```python
import sqlite3
from flask import g

DATABASE = 'database.db'

def get_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)
        db.row_factory = sqlite3.Row
    return db

@app.teardown_appcontext
def close_connection(exception):
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

def query_db(query, args=(), one=False):
    cur = get_db().execute(query, args)
    rv = cur.fetchall()
    cur.close()
    return (rv[0] if rv else None) if one else rv
```

### Using SQL Alchemy
```python
from flask_sqlalchemy import SQLAlchemy

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    email = db.Column(db.String(120), unique=True, nullable=False)

    def __repr__(self):
        return f'<User {self.username}>'
```

## Application Structure

### Configuration
```python
# config.py
import os

class Config:
    SECRET_KEY = os.environ.get('SECRET_KEY') or 'hard-to-guess-string'
    SQLALCHEMY_DATABASE_URI = os.environ.get('DATABASE_URL') or \
        'sqlite:///app.db'
    SQLALCHEMY_TRACK_MODIFICATIONS = False
```

### Application Factory
```python
# app/__init__.py
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager
from config import Config

db = SQLAlchemy()
login = LoginManager()
login.login_view = 'auth.login'

def create_app(config_class=Config):
    app = Flask(__name__)
    app.config.from_object(config_class)

    db.init_app(app)
    login.init_app(app)

    from app.main import bp as main_bp
    app.register_blueprint(main_bp)

    from app.auth import bp as auth_bp
    app.register_blueprint(auth_bp, url_prefix='/auth')

    return app
```

## Best Practices

### Security
1. Use HTTPS
2. Hash passwords
3. Validate user input
4. Protect against CSRF
5. Use secure session configuration

### Performance
1. Use caching
2. Optimize database queries
3. Minimize external requests
4. Use asynchronous operations when appropriate
5. Implement proper error handling

### Code Organization
1. Use blueprints
2. Follow MVC pattern
3. Implement proper logging
4. Write tests
5. Document your code

## Additional Resources

- [CS50 Flask Notes](https://cs50.harvard.edu/x/2024/notes/9/)
- [Flask Documentation](https://flask.palletsprojects.com/)
- [Flask SQLAlchemy](https://flask-sqlalchemy.palletsprojects.com/)
- [Flask Security Best Practices](https://flask.palletsprojects.com/en/2.0.x/security/)
- [Flask Mega-Tutorial](https://blog.miguelgrinberg.com/post/the-flask-mega-tutorial-part-i-hello-world)