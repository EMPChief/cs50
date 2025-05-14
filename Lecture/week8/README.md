 # Week 8: Web Development

This document provides a comprehensive overview of Week 8 topics in CS50, covering web development fundamentals including HTML, CSS, and JavaScript.

## Table of Contents
1. [Internet Basics](#internet-basics)
2. [HTML](#html)
3. [CSS](#css)
4. [JavaScript](#javascript)
5. [DOM Manipulation](#dom-manipulation)
6. [Forms and Validation](#forms-and-validation)
7. [Responsive Design](#responsive-design)

## Internet Basics

### How the Web Works
- HTTP/HTTPS protocols
- Client-server model
- DNS resolution
- IP addressing
- TCP/IP

### Request-Response Cycle
1. Client sends request
2. Server processes request
3. Server sends response
4. Client renders response

## HTML

### Basic Structure
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Web Page</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Welcome to My Page</h1>
    <p>This is a paragraph.</p>
</body>
</html>
```

### Common Elements
```html
<!-- Headings -->
<h1>Main Title</h1>
<h2>Subtitle</h2>

<!-- Text -->
<p>Paragraph</p>
<strong>Bold text</strong>
<em>Italic text</em>

<!-- Lists -->
<ul>
    <li>Unordered item</li>
</ul>
<ol>
    <li>Ordered item</li>
</ol>

<!-- Links -->
<a href="https://example.com">Click here</a>

<!-- Images -->
<img src="image.jpg" alt="Description">

<!-- Tables -->
<table>
    <tr>
        <th>Header</th>
    </tr>
    <tr>
        <td>Data</td>
    </tr>
</table>
```

## CSS

### Selectors and Properties
```css
/* Element selector */
p {
    color: blue;
    font-size: 16px;
}

/* Class selector */
.highlight {
    background-color: yellow;
}

/* ID selector */
#header {
    text-align: center;
}

/* Combinators */
div > p {
    margin: 10px;
}
```

### Box Model
```css
.box {
    margin: 10px;
    border: 1px solid black;
    padding: 15px;
    width: 300px;
    height: 200px;
}
```

### Flexbox
```css
.container {
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.item {
    flex: 1;
    margin: 5px;
}
```

### Grid
```css
.grid-container {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 20px;
}
```

## JavaScript

### Basic Syntax
```javascript
// Variables
let name = "CS50";
const PI = 3.14159;

// Functions
function greet(name) {
    return `Hello, ${name}!`;
}

// Arrays
let numbers = [1, 2, 3, 4, 5];
numbers.forEach(num => console.log(num));

// Objects
let person = {
    name: "John",
    age: 30,
    greet() {
        console.log(`Hello, I'm ${this.name}`);
    }
};
```

### DOM Manipulation
```javascript
// Selecting elements
let element = document.getElementById('myId');
let elements = document.getElementsByClassName('myClass');
let query = document.querySelector('.myClass');

// Modifying elements
element.innerHTML = 'New content';
element.style.color = 'red';
element.classList.add('newClass');

// Creating elements
let newDiv = document.createElement('div');
newDiv.textContent = 'Hello World';
document.body.appendChild(newDiv);

// Event handling
element.addEventListener('click', function(e) {
    console.log('Element clicked!');
});
```

## Forms and Validation

### HTML Forms
```html
<form action="/submit" method="POST">
    <div>
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required>
    </div>
    
    <div>
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>
    </div>
    
    <div>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required>
    </div>
    
    <button type="submit">Submit</button>
</form>
```

### JavaScript Validation
```javascript
const form = document.querySelector('form');
form.addEventListener('submit', function(e) {
    e.preventDefault();
    
    const username = document.getElementById('username').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    
    if (username.length < 3) {
        alert('Username must be at least 3 characters');
        return;
    }
    
    if (!email.includes('@')) {
        alert('Please enter a valid email');
        return;
    }
    
    if (password.length < 8) {
        alert('Password must be at least 8 characters');
        return;
    }
    
    // If validation passes, submit the form
    form.submit();
});
```

## Responsive Design

### Media Queries
```css
/* Mobile first approach */
.container {
    width: 100%;
    padding: 15px;
}

/* Tablet */
@media (min-width: 768px) {
    .container {
        width: 750px;
        margin: 0 auto;
    }
}

/* Desktop */
@media (min-width: 1024px) {
    .container {
        width: 970px;
    }
}
```

### Responsive Images
```css
img {
    max-width: 100%;
    height: auto;
}
```

### Responsive Typography
```css
html {
    font-size: 16px;
}

@media (min-width: 768px) {
    html {
        font-size: 18px;
    }
}

h1 {
    font-size: 2rem;
}

p {
    font-size: 1rem;
    line-height: 1.5;
}
```

## Best Practices

### HTML
1. Use semantic elements
2. Validate your HTML
3. Include proper meta tags
4. Optimize images
5. Use descriptive alt text

### CSS
1. Follow a naming convention
2. Minimize specificity
3. Use CSS reset/normalize
4. Organize your styles
5. Comment your code

### JavaScript
1. Use strict mode
2. Handle errors properly
3. Avoid global variables
4. Use modern ES6+ features
5. Minify for production

## Additional Resources

- [CS50 Web Programming Notes](https://cs50.harvard.edu/x/2024/notes/8/)
- [MDN Web Docs](https://developer.mozilla.org/)
- [W3C Validation Service](https://validator.w3.org/)
- [Can I Use](https://caniuse.com/)
- [Web Development Roadmap](https://roadmap.sh/frontend)