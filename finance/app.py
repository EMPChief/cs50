import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, is_int

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Hent brukerens aksjeportefølje fra databasen
    user_portfolio = db.execute(
        "SELECT id, symbol, name, SUM(shares) FROM trades WHERE id = ? GROUP BY symbol HAVING SUM(shares) > 0 ORDER BY price DESC", session["user_id"])

    # Hent brukerens kontantsaldo fra databasen
    user_cash = db.execute(
        "SELECT * FROM users WHERE id = ?", session["user_id"])

    # Oppdater user_portfolio med aksjens nåværende pris og total faktisk pris for aksjene
    current_worth = 0
    for stock in user_portfolio:
        stock_data = lookup(stock["symbol"])
        stock["currentprice"] = stock_data["price"]
        stock["totalprice"] = stock_data["price"] * stock["SUM(shares)"]
        current_worth += stock["totalprice"]

    return render_template("index.html", user_portfolio=user_portfolio, user_cash=user_cash, current_worth=current_worth)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares_nbr = request.form.get("shares")

        # Sørg for at symbolet ikke er tomt
        if symbol == "":
            return apology("MISSING SYMBOL", 400)
        if shares_nbr == "" or shares_nbr.isalpha():
            return apology("MISSING SHARES", 400)
        if not is_int(shares_nbr):
            return apology("fractional not supported", 400)
        if int(shares_nbr) <= 0:
            return apology("share number can't be negative number or zero!", 400)

        # Hent aksjekurs
        stock_quote = lookup(symbol)

        if not stock_quote:
            return apology("INVALID SYMBOL", 400)

        # Beregn total kostnad
        total_cost = int(shares_nbr) * stock_quote["price"]

        # Hent brukerens nåværende kontantsaldo
        user_cash = db.execute(
            "SELECT * FROM users WHERE id = ?", session["user_id"])

        # Sørg for at brukeren har råd til kjøpet
        if user_cash[0]["cash"] < total_cost:
            return apology("CAN'T AFFORD", 400)

        else:
            # Registrer kjøpet i trades-tabellen
            db.execute("INSERT INTO trades (id, symbol, name, shares, price) VALUES(?, ?, ?, ?, ?)",
                       session["user_id"], stock_quote['symbol'], stock_quote['name'], int(shares_nbr), stock_quote['price'])
            # Oppdater brukerens kontantsaldo
            cash = user_cash[0]["cash"]
            db.execute("UPDATE users SET cash = ? WHERE id = ?",
                       cash - total_cost, session["user_id"])
            flash('Bought!')
            return redirect("/")

    # Vis kjøpsside
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Hent brukerens transaksjonshistorikk fra databasen
    user_transactions = db.execute(
        "SELECT id, symbol, shares, price, transacted FROM trades WHERE id = ? ORDER BY transacted", session["user_id"])

    return render_template("history.html", user_transactions=user_transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Fjern eventuell eksisterende user_id
    session.clear()

    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":

        # Sørg for at brukernavn ble sendt inn
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Sørg for at passord ble sendt inn
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Hent bruker fra databasen
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Sørg for at brukernavn eksisterer og passord er korrekt
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Husk hvilken bruker som har logget inn
        session["user_id"] = rows[0]["id"]

        # Omdiriger brukeren til hjemmesiden
        return redirect("/")

    # Vis innloggingsside
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Fjern user_id fra sesjonen
    session.clear()

    # Omdiriger brukeren til innloggingsskjemaet
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        # Sørg for at symbolet ikke er tomt
        if symbol == "":
            return apology("input is blank", 400)

        # Hent aksjekurs
        stock_quote = lookup(symbol)

        if not stock_quote:
            return apology("INVALID SYMBOL", 400)
        else:
            return render_template("quoted.html", symbol=stock_quote)

    # Vis sitat-side
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Fjern eventuell eksisterende user_id
    session.clear()

    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":

        # Valider innsending
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Sjekk om brukernavnet allerede eksisterer
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Sørg for at passord og bekreftelse matcher
        if not (password == confirmation):
            return apology("the passwords do not match", 400)

        # Sørg for at ingen felter er tomme
        if password == "" or confirmation == "" or username == "":
            return apology("input is blank", 400)

        # Sørg for at brukernavnet ikke allerede eksisterer
        if len(rows) == 1:
            return apology("username already exist", 400)
        else:
            # Lag en hash av passordet og lagre brukerinformasjonen i databasen
            hashcode = generate_password_hash(
                password, method='pbkdf2:sha256', salt_length=8)
            db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)", username, hashcode)

        # Omdiriger brukeren til hjemmesiden
        return redirect("/")

    # Vis registreringsside
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares_nbr = request.form.get("shares")

        # Sørg for at symbolet ikke er tomt
        if symbol == "":
            return apology("MISSING SYMBOL", 400)
        if shares_nbr == "" or shares_nbr.isalpha():
            return apology("MISSING SHARES", 400)
        if not is_int(shares_nbr):
            return apology("fractional not supported", 400)
        if int(shares_nbr) <= 0:
            return apology("share number can't be negative number or zero!", 400)

        # Hent aksjekurs
        stock_quote = lookup(symbol)

        if not stock_quote:
            return apology("INVALID SYMBOL", 400)

        # Hent brukerens nåværende aksjeportefølje
        user_shares = db.execute(
            "SELECT symbol, SUM(shares) FROM trades WHERE id = ? GROUP BY symbol HAVING symbol = ?", session["user_id"], symbol)

        if not user_shares or user_shares[0]['SUM(shares)'] < int(shares_nbr):
            return apology("NOT ENOUGH SHARES", 400)

        # Beregn total inntekt
        total_income = int(shares_nbr) * stock_quote["price"]

        # Registrer salget i trades-tabellen
        db.execute("INSERT INTO trades (id, symbol, name, shares, price) VALUES(?, ?, ?, ?, ?)",
                   session["user_id"], stock_quote['symbol'], stock_quote['name'], -int(shares_nbr), stock_quote['price'])
        # Oppdater brukerens kontantsaldo
        user_cash = db.execute(
            "SELECT * FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        db.execute("UPDATE users SET cash = ? WHERE id = ?",
                   user_cash + total_income, session["user_id"])
        flash('Sold!')
        return redirect("/")

    # Vis salgsside
    else:
        # Hent brukerens aksjeportefølje
        user_shares = db.execute(
            "SELECT symbol FROM trades WHERE id = ? GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])
        return render_template("sell.html", user_shares=user_shares)


@app.route("/settings")
@login_required
def settings():
    """Show settings"""
    # Hent brukernavn fra databasen
    username = db.execute(
        "SELECT username FROM users WHERE id = ?", session["user_id"])
    return render_template("settings.html", username=username[0]['username'])


@app.route("/passwordupdate", methods=["GET", "POST"])
@login_required
def passwordupdate():
    """Update password"""

    # Håndter POST-forespørsel (skjemainnsending)
    if request.method == "POST":

        # Valider innsending
        currentpassword = request.form.get("currentpassword")
        newpassword = request.form.get("newpassword")
        confirmation = request.form.get("confirmation")

        # Hent bruker fra databasen
        rows = db.execute("SELECT * FROM users WHERE id = ?",
                          session["user_id"])

        # Sørg for at nytt passord matcher bekreftelsen
        if not (newpassword == confirmation):
            return apology("The passwords do not match", 400)

        # Sørg for at ingen felter er tomme
        if currentpassword == "" or newpassword == "" or confirmation == "":
            return apology("Input is blank", 400)

        # Sørg for at nåværende passord er korrekt
        if not check_password_hash(rows[0]["hash"], currentpassword):
            return apology("Invalid password", 403)
        else:
            # Lag en hash av det nye passordet og oppdater i databasen
            hashcode = generate_password_hash(
                newpassword, method='pbkdf2:sha256', salt_length=8)
            db.execute("UPDATE users SET hash = ? WHERE id = ?",
                       hashcode, session["user_id"])

        # Omdiriger brukeren til innstillingssiden
        return redirect("/settings")

    # Vis siden for passordoppdatering
    else:
        return render_template("passwordupdate.html")


def get_time():
    """Return formatted local time."""
    return datetime.now().strftime("%d-%m-%Y %H:%M:%S")


def check_password(stored_password_hash, provided_password):
    """Checks if the passwords match. Returns an error message if they do not match."""
    if not check_password_hash(stored_password_hash, provided_password):
        return apology("The passwords do not match!", 401)


@app.route("/withdraw", methods=["GET", "POST"])
@login_required
def withdraw():
    """Withdraw money from account."""

    # Brukeren har nådd ruten via POST (f.eks. ved å sende inn et skjema)
    if request.method == "POST":
        user_id = session["user_id"]

        # Hent beløpet fra skjemaet og konverter til heltall
        amount = int(request.form.get("sum"))

        # Hent kontoopplysninger for brukeren
        account = db.execute("SELECT * FROM users WHERE id = ?", user_id)

        # Kontroller at passordet er korrekt
        password_check = check_password(
            account[0]["hash"], request.form.get("password"))
        if password_check:
            return password_check  # Dette vil returnere apology hvis passordene ikke stemmer

        # Kontroller at brukeren ikke kan ta ut mer enn tilgjengelig saldo
        if amount > account[0]["cash"]:
            return apology("Cannot withdraw more than available balance!")

        # Trekker beløpet fra kontosaldoen
        cash = account[0]["cash"] - amount
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)

        # Logg transaksjonen med tidsstempel
        db.execute("INSERT INTO transactions (user_id, type, amount, timestamp) VALUES (?, ?, ?, ?)",
                   user_id, "withdrawal", amount, get_time())

        flash(f"Successful withdrawal of ${amount} from your balance!")
        return redirect("/")

    # Brukeren har nådd ruten via GET (f.eks. ved å klikke på en lenke eller ved omdirigering)
    return render_template("withdraw.html")


@app.route("/deposit", methods=["GET", "POST"])
@login_required
def deposit():
    """Deposit money into account."""
    try:
        # Hvis brukeren sender inn skjemaet via POST
        if request.method == "POST":
            user_id = session["user_id"]

            amount = int(request.form.get("sum"))
            account = db.execute("SELECT * FROM users WHERE id = ?", user_id)

            # Sjekk at passordet er korrekt
            password_check = check_password(
                account[0]["hash"], request.form.get("password"))
            if password_check:
                return password_check  # Dette vil returnere apology hvis passordene ikke stemmer

            # Legg til midler på kontoen
            cash = account[0]["cash"] + amount
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)

            # Logg transaksjonen med tidsstempel
            db.execute("INSERT INTO transactions (user_id, type, amount, timestamp) VALUES (?, ?, ?, ?)",
                       user_id, "deposit", amount, get_time())

            flash(f"Successful deposit of ${amount} to your balance!")
            return redirect("/")

        # Hvis brukeren åpner siden via GET
        return render_template("deposit.html")
    except Exception as e:
        return apology(f"An error occurred: {e}", 500)
