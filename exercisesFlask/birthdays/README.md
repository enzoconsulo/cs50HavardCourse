# BIRTHDAYS (Flask, HTML & SQLite)

**Simple web application to store birthdays (CS50 Lab 9 — Birthdays)**

Following CS50 Lab 9 specification:  
https://cs50.harvard.edu/x/2021/labs/9/

This directory contains a minimal implementation of the CS50 "Birthdays" lab: a small Flask app that uses SQLite to save and display birthdays. The README below was created from the files in your zip (`birthdays.zip`) — it is faithful to what currently exists in the extracted folder.

---

## Files present

* `app.py` — main Flask application (contains route `/` for GET and POST).  

* `birthdays.db` — SQLite database already included (table `birthdays` expected by the app).  
* `templates/index.html` — Jinja2 template used as the main page. Contains the form to insert birthdays and a Jinja loop to display records (`{% for birthday in birthdays %}`), plus a `<!-- TODO: ... -->` comment.  
* `static/styles.css` — CSS styles used by the template.  
* `__pycache__/` — Python cache (ignore).

---

## Database schema (expected)

The implementation follows the lab prompt: the `birthdays` table should have, at minimum, the columns:

* `id` — INTEGER PRIMARY KEY  
* `name` — TEXT  
* `month` — INTEGER  
* `day` — INTEGER

(The `birthdays.db` file is already included in the zip; if you open it with a SQLite client you will see the table.)

---

## How it works (based on current files)

1. **Route `/` — GET**  
   * `app.py` runs `SELECT * FROM birthdays` and renders `index.html`, passing `birthdays` to the template.  
   * `templates/index.html` iterates over `birthdays` and shows each record in a `<table>` (columns: name and `month / day`).

2. **Route `/` — POST**  
   * The form in `index.html` sends `name`, `month`, and `day` to `/` via POST.  
   * `app.py` reads `request.form.get("name")`, `request.form.get("month")`, `request.form.get("day")` and executes:
     ```
     db.execute("INSERT INTO birthdays (name,month,day) VALUES (?,?,?)", name, month, day)
     ```
   * After the `INSERT`, the app redirects back to `/` (to display the updated list).

3. **Front-end**  
   * The template uses `static/styles.css` for styling.  
   * There are `TODO` comments in the template, but the display loop is already present.

---

## How to run (locally)

  Install dependencies and flask on your pc and run:
  ```
  flask run
  ```

---

Developed by Enzo C. Consulo as part of Harvard’s CS50 coursework (2025).