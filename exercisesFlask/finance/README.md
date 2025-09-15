# FINANCE (Flask, SQLite & Jinja2)

**Simple web application to simulate stock trading (CS50 — Finance)**

Following CS50 Lab 9 specification:  
https://cs50.harvard.edu/x/psets/9/finance/

This README describes the implementation found in the extracted `finance` folder and explains concisely how the application works so a reader on GitHub can quickly understand the project.

---

## Files present

* `app.py` — main Flask application (routes for portfolio, buy, sell, quote, register, login, logout, history).
* `helpers.py` — utility functions used across the app (`lookup()` for price data, `usd()` for formatting, `apology()` template helper, and `login_required` decorator).
* `requirements.txt` — Python dependencies required to run the app.
* `finance.db` — SQLite database (may already be included). Stores users and transaction history.
* `templates/` — Jinja2 templates: `layout.html`, `index.html`, `buy.html`, `sell.html`, `quote.html`, `register.html`, `login.html`, `history.html`, etc.
* `static/` — CSS, JavaScript and images used by templates.
* `flask_session/` — server-side session files (if present).

---

## Database schema (expected)

Typical tables and important columns used by this implementation:

* `users` — `id` (INTEGER PRIMARY KEY), `username` (TEXT), `hash` (TEXT, password hash), `cash` (NUMERIC default starting balance).
* `history` — `owner_id` (user id), `symbol`, `shares` (positive for purchase, negative for sale or a separate `type` column), `price`, `date` (timestamp).
* `quote` or `positions` (optional) — snapshot of current holdings (some implementations compute positions by aggregating `history`).

The app records every transaction in `history`. Current holdings are either read from a `quote`/`positions` table or computed by summing `history` grouped by `symbol` and `owner_id`.

---

## How it works (concise)

1. **Authentication**

   * Users register with a username and password. Passwords are stored as secure hashes in the `users` table.
   * After login, the user session stores the `user_id` to identify requests.

2. **Price lookup**

   * The app provides a quote form where users can request the current price of a ticker symbol using `helpers.lookup()`. The lookup function calls an external quote service (the project expects the CS50-compatible endpoint used in the exercise).

3. **Buying shares**

   * The `/buy` route accepts a symbol and number of shares.
   * The server validates input, fetches the current price via `lookup()`, checks the user has enough `cash`, deducts the cost from `cash`, writes a `history` record for the purchase, and updates holdings.

4. **Selling shares**

   * The `/sell` route lists the user’s owned symbols and accepts a quantity to sell.
   * The server verifies ownership and quantity, fetches the current price, increases `cash` by the sale proceeds, and writes a `history` record for the sale.

5. **Portfolio & history**n

   * The index (`/`) shows the user’s current portfolio: each symbol, quantity owned, current price (from `lookup()`), total value per holding, cash on hand, and total account value.
   * The `/history` page shows chronological transactions (buy/sell), with timestamps and per-share prices.

---

## Key routes (summary)

* `GET /` — Portfolio (current holdings, cash, account value).
* `GET|POST /register` — Register a new user.
* `GET|POST /login` — Log in an existing user.
* `GET /logout` — Log out and clear session.
* `GET|POST /quote` — Look up the current price of a symbol.
* `GET|POST /buy` — Buy shares.
* `GET|POST /sell` — Sell shares.
* `GET /history` — View transaction history.

---

## How to run (quick start)

1. Create and activate a virtual environment (recommended):

```bash
python -m venv .venv
source .venv/bin/activate   # macOS/Linux
.\\.venv\\Scripts\\activate  # Windows (PowerShell or CMD)
```

2. Install dependencies:

```bash
pip install -r requirements.txt
```

3. Run the app:

```bash
flask run
```

On Windows PowerShell:

```powershell
$env: flask run
```

4. Open `http://127.0.0.1:5000/` in a browser, register a user and explore the buy/sell/quote flows.

---

## Notes for a GitHub reader

* This repository is a teaching exercise demonstrating web app fundamentals: routing, templating, database use, sessions, and consuming an external API for quotes.
* If the repository contains `venv/`, `flask_session/` or a populated `finance.db`, consider removing or adding them to `.gitignore` before publishing to avoid exposing sensitive or bulky files.

---

Developed by Enzo C. Consulo as part of CS50 coursework (2025).
