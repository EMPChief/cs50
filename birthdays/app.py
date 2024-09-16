from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Set a secret key for the application
app.secret_key = 'your_secret_key_here'

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        lastname = request.form.get("lastname")
        birthday = request.form.get("birthday")

        if name and lastname and birthday:
            # Ekstraher år, måned, og dag fra bursdagsdatoen
            year, month, day = birthday.split('-')

            # Sett inn bursdagsinformasjonen i databasen
            db.execute(
                "INSERT INTO birthdays (name, lastname, month, day, year) VALUES (?, ?, ?, ?, ?)",
                name, lastname, int(month), int(day), int(year)
            )
            # Vis en suksessmelding
            flash("Birthday added successfully!", "success")
            return redirect("/")
        else:
            # Hvis noen av feltene er tomme, vis en feilmelding
            flash("Please fill in all fields", "error")
            return redirect("/")

    else:
        # Hent alle bursdager fra databasen for å vise dem på nettsiden
        get_birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", get_birthdays=get_birthdays)


@app.route("/delete/<int:id>", methods=["POST"])
def delete(id):
    # Slett bursdagen med gitt id fra databasen
    db.execute("DELETE FROM birthdays WHERE id = ?", id)
    # Vis en suksessmelding
    flash("Birthday deleted successfully!", "success")
    return redirect("/")


@app.route("/edit/<int:id>", methods=["GET", "POST"])
def edit(id):
    if request.method == "POST":
        name = request.form.get("name")
        lastname = request.form.get("lastname")
        birthday = request.form.get("birthday")

        if name and lastname and birthday:
            # Ekstraher år, måned, og dag fra bursdagsdatoen
            year, month, day = birthday.split('-')

            # Oppdater bursdagsinformasjonen i databasen
            db.execute(
                "UPDATE birthdays SET name = ?, lastname = ?, month = ?, day = ?, year = ? WHERE id = ?",
                name, lastname, int(month), int(day), int(year), id
            )
            # Vis en suksessmelding
            flash("Birthday updated successfully!", "success")
            return redirect("/")
        else:
            # Hvis noen av feltene er tomme, vis en feilmelding
            flash("Please fill in all fields", "error")
            return redirect(f"/edit/{id}")

    else:
        # Hent eksisterende bursdagsinformasjon fra databasen
        birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)
        if len(birthday) != 1:
            flash("Birthday not found", "error")
            return redirect("/")
        return render_template("edit.html", birthday=birthday[0])


if __name__ == "__main__":
    app.run(debug=True)
