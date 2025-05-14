from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, url_for

# Konfigurer applikasjonen
app = Flask(__name__)

# Sett en hemmelig nøkkel for applikasjonen (bør erstattes med en sikker nøkkel i produksjon)
app.secret_key = 'your_secret_key_here'

# Sørg for at malene lastes inn på nytt automatisk når de endres
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Konfigurer CS50-biblioteket til å bruke SQLite-databasen
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Sørg for at responser ikke bufres."""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Hent data fra skjemaet og fjern ledende og etterfølgende mellomrom
        name = request.form.get("name").strip()
        lastname = request.form.get("lastname").strip()
        birthday = request.form.get("birthday")

        # Valider at alle feltene er fylt ut
        if not name or not lastname or not birthday:
            flash("Please fill in all fields.", "error")
            return redirect(url_for('index'))

        # Prøv å ekstrahere år, måned og dag fra bursdagsdatoen
        try:
            year, month, day = map(int, birthday.split('-'))
        except ValueError:
            # Hvis datoformatet er feil, vis en feilmelding
            flash("Invalid date format.", "error")
            return redirect(url_for('index'))

        # Sett inn bursdagen i databasen med kapitalisert navn og etternavn
        db.execute(
            "INSERT INTO birthdays (name, lastname, month, day, year) VALUES (?, ?, ?, ?, ?)",
            name.capitalize(), lastname.capitalize(), month, day, year
        )
        # Vis en suksessmelding til brukeren
        flash("Birthday added successfully!", "success")
        return redirect(url_for('index'))

    else:
        # Hvis forespørselen er GET, hent alle bursdager fra databasen sortert etter måned og dag
        get_birthdays = db.execute(
            "SELECT * FROM birthdays ORDER BY month, day")
        # Gjengir hovedsiden med listen over bursdager
        return render_template("index.html", get_birthdays=get_birthdays)


@app.route("/delete/<int:id>", methods=["POST"])
def delete(id):
    # Slett bursdagen med gitt id fra databasen
    db.execute("DELETE FROM birthdays WHERE id = ?", id)
    # Vis en suksessmelding til brukeren
    flash("Birthday deleted successfully!", "success")
    return redirect(url_for('index'))


@app.route("/edit/<int:id>", methods=["GET", "POST"])
def edit(id):
    if request.method == "POST":
        # Hent data fra skjemaet og fjern ledende og etterfølgende mellomrom
        name = request.form.get("name").strip()
        lastname = request.form.get("lastname").strip()
        birthday = request.form.get("birthday")

        # Valider at alle feltene er fylt ut
        if not name or not lastname or not birthday:
            flash("Please fill in all fields.", "error")
            return redirect(url_for('edit', id=id))

        # Prøv å ekstrahere år, måned og dag fra bursdagsdatoen
        try:
            year, month, day = map(int, birthday.split('-'))
        except ValueError:
            # Hvis datoformatet er feil, vis en feilmelding
            flash("Invalid date format.", "error")
            return redirect(url_for('edit', id=id))

        # Oppdater bursdagen i databasen med nye verdier
        db.execute(
            "UPDATE birthdays SET name = ?, lastname = ?, month = ?, day = ?, year = ? WHERE id = ?",
            name.capitalize(), lastname.capitalize(), month, day, year, id
        )
        # Vis en suksessmelding til brukeren
        flash("Birthday updated successfully!", "success")
        return redirect(url_for('index'))

    else:
        # Hent eksisterende bursdag fra databasen basert på id
        birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)
        if len(birthday) != 1:
            # Hvis bursdagen ikke finnes, vis en feilmelding
            flash("Birthday not found.", "error")
            return redirect(url_for('index'))
        # Gjengir redigeringssiden med eksisterende bursdagsdata
        return render_template("edit.html", birthday=birthday[0])


@app.route("/search", methods=["GET"])
def search():
    # Hent søkestrengen fra forespørselen og fjern ledende og etterfølgende mellomrom
    query = request.args.get("q", "").strip()
    if query:
        # Søk etter bursdager hvor navn eller etternavn matcher søkestrengen
        get_birthdays = db.execute(
            "SELECT * FROM birthdays WHERE name LIKE ? OR lastname LIKE ? ORDER BY month, day",
            f"%{query}%", f"%{query}%"
        )
        if not get_birthdays:
            # Hvis ingen bursdager finnes, vis en informasjonsmelding
            flash("No birthdays found matching your search.", "info")
    else:
        # Hvis søkestrengen er tom, vis en feilmelding
        flash("Please enter a name to search.", "error")
        return redirect(url_for('index'))
    # Gjengir hovedsiden med søkeresultatene
    return render_template("index.html", get_birthdays=get_birthdays, query=query)


if __name__ == "__main__":
    app.run(debug=True)
