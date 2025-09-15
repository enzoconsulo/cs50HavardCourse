import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


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
    noQuotes = False
    search = {}
    cash = 0
    totalQuotesPrice = 0
    try:
        
        search = db.execute("SELECT shares,symbol,price FROM quote WHERE owner_id = ?", session["user_id"])
          
        for quote in search:
            
            totalQuotesPrice += float(quote["price"]) * float(quote["shares"])
            
            quote["total"] = usd(float(quote["price"]) * float(quote["shares"]))
            quote["price"] = usd(quote["price"])
            
        
        search1 = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = usd(search1[0]["cash"])
        
    except:
        noQuotes = True
        
    if search == []:
        noQuotes = True
        
    return render_template("index.html",quotes = search, noQuotes = noQuotes, cash = cash, totalQuotesPrice = usd(totalQuotesPrice))
    

def isInteger(string):
    if string.isdigit():
        return True
    
    if not string[0].isdigit() and string[0] == '+' :
        if string[1:].isdigit():
            return True
        
    return False
        
    
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").lower()
        search = lookup(symbol)
        
        shares = request.form.get("shares")
        
        if symbol == "":
            flash("'Quote Symbol' cannot be empty")
            return redirect("/buy")
        
        elif search == None:
            flash("Quote '"+ symbol +"' not found")
            return redirect("/buy")
        
        elif shares == "":
            flash("'Shares' cannot be empty")
            return redirect("/buy")
        
        elif not isInteger(shares):
            flash("Please type a positive integer")
            return redirect("/buy")
        
        #   get the cash from user
        cash = db.execute("SELECT cash FROM users"
                        + " WHERE id = ?;" , session["user_id"])
        
        #   calculates total price from buy
        price = search["price"] * int(shares)
        if price <= cash[0]["cash"]:
            
            #   deduct total price from user cash
            db.execute("UPDATE users"
                    +  " SET cash = cash - ?"
                    +  " WHERE id = ? ;",price,session["user_id"])
            
            #   if table "quote" does not exist, creates
            # "quote" is the table to save amount of shares and his owners
            db.execute("CREATE TABLE IF NOT EXISTS quote ("
                        + "shares INT,"
                        + "symbol VARCHAR(10),"
                        + "owner_id INT,"
                        + "price DOUBLE,"
                        + "FOREIGN KEY (owner_id) REFERENCES users(id) );"
                    )
            
            sharesBuyed = db.execute("SELECT shares FROM quote WHERE symbol = ? AND owner_id = ?",symbol, session["user_id"])
            
            if sharesBuyed == []:
                db.execute("INSERT INTO quote (shares,symbol,owner_id,price) VALUES (?,?,?,?)", int(shares) , symbol , session["user_id"], search["price"] )
            else:
                db.execute("UPDATE quote SET shares = shares + ? WHERE owner_id = ?", int(shares), session["user_id"])
                
            #   if table "history" does not exist, creates
            # "history" is the table to save history of buy shares and his owners
            db.execute("CREATE TABLE IF NOT EXISTS history ("
                        + "shares INT,"
                        + "symbol VARCHAR(10),"
                        + "owner_id INT,"
                        + "date DATETIME,"
                        + "price DOUBLE,"
                        + "type VARCHAR(4),"
                        + "FOREIGN KEY (owner_id) REFERENCES users(id) );"
                    )
            
            db.execute("INSERT INTO history (shares,symbol,owner_id,date,price,type) VALUES (?,?,?,CURRENT_TIMESTAMP,?,?)", int(shares) , symbol , session["user_id"],search["price"],"BUY" )
            
            flash("Buyed!")
            return redirect("/")
        
        else:
            flash("Insuficient Balance!")
            return redirect("/buy")


    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    
    search = db.execute("SELECT * FROM history WHERE owner_id = ?",session["user_id"])
    for quote in search:
        quote["total"] = usd(float(quote["price"]) * int(quote["shares"]))
        quote["price"] = usd(quote["price"])
        
    return render_template("history.html",quotes = search)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol").lower()
        search = lookup(symbol)
        
        if (symbol == ""):
            flash("'Quote Symbol' cannot be empty")
            return redirect("/quote")
        
        elif search == None:
            flash("Quote '"+ symbol +"' not found")
            return redirect("/quote")
        
        return redirect(url_for("quoted", symbol=symbol))
        
    return render_template("quote.html")

@app.route("/quoted/<symbol>", methods=["GET"])
@login_required
def quoted(symbol):
    """Get stock quote."""
    search = lookup(symbol)
    
    if(search != None):
        return render_template("quoted.html",search = search , searchprice=usd(search["price"]))
    
    elif (symbol == "quote.html"):
        return redirect("/quote")
    
    else:
        flash("Quote '"+ symbol +"' not found")
        return redirect("/quote")
    



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        
        
        try:
            id = db.execute("INSERT INTO users (username,hash) VALUES (?,?)",username,generate_password_hash(password))
            flash("Account was succesfully created !")
            session["user_id"] = id
            return redirect("/")
        except:
            flash("This username is already used ! ")
            return redirect("/register")
        
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    
    if request.method == "POST":
        symbol = request.form.get("quoteselect")
        sellingshares = request.form.get("shares")
        try:
            actualshares = db.execute("SELECT shares,price FROM quote WHERE symbol = ? AND owner_id = ?",symbol,session["user_id"])
            
            newshares = actualshares[0]["shares"] - int(sellingshares)
            
            if(newshares >= 0):
                if newshares == 0:
                    # remove the row from this symbol to clean quote table bcs will be "0". So no quote has left
                    db.execute("DELETE FROM quote WHERE symbol = ? AND owner_id = ?",symbol,session["user_id"])
                else:
                    # remove from quotes the amount to sell
                    db.execute("UPDATE quote SET shares = ? WHERE symbol = ? AND owner_id = ?",newshares,symbol,session["user_id"])

                # update the cash/balance adding the sellingPrice
                sellingPrice = float(sellingshares)*actualshares[0]["price"]
                db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",sellingPrice,session["user_id"])
                
                
                db.execute("INSERT INTO history (shares,symbol,owner_id,date,price,type) VALUES (?,?,?,CURRENT_TIMESTAMP,?,?)", int(sellingshares) , symbol , session["user_id"],actualshares[0]["price"],"SELL" )
                flash(f"Sucess! You sold {usd(sellingPrice)} : {int(sellingshares)} '{symbol.upper()}' quotes {usd(actualshares[0]["price"])} each")
                return redirect("/")
                
                
            else:
                flash("Insuficient quotes to sell")
                return redirect("/sell")

        except: 
            flash("Action is not possible")
            return redirect("/sell")
        
    
    search = db.execute("SELECT symbol FROM quote WHERE owner_id = ?", session["user_id"])
    return render_template("sell.html",symbols = search)
