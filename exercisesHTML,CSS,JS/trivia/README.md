# TRIVIA (HTML, CSS & JS) PROJECT

**Simple client-side Trivia quiz (CS50 Lab 8 — Trivia)**

Following CS50 Lab 8 specification:  
https://cs50.harvard.edu/x/2021/labs/8/

This folder contains a minimal, static trivia page implemented with plain HTML, CSS and inline JavaScript. It does **not** fetch external question files — all logic is embedded directly in `index.html`.

---

## Files in this folder

* `index.html` — main page (contains markup and inline JS that handles both the multiple-choice and free-response questions).  
* `styles.css` — stylesheet referenced by `index.html` (present in repo).

> Note: there is **no** `script.js` or `questions.json` used by this implementation — the JS lives inside `index.html`.

---

## How it currently works

1. **Multiple choice (Part 1)**  
   * Buttons with ids `#david`, `#wrong1`, `#wrong2`, `#wrong3`, `#wrong4` are wired in an inline `DOMContentLoaded` listener.  
   * Clicking the correct button (`#david`) turns it green and shows an `alert("RIGHT!!")`. Wrong buttons turn red and show `alert("WRONG!")`.

2. **Free response (Part 2)**  
   * A text input with id `#part2` and a button that calls `checkAnswer()` on click.  
   * `checkAnswer()` normalizes the input and checks if it equals `"washington"` (case-insensitive). If so, it colors the input green and alerts a success message; otherwise it alerts wrong.

3. **No server required** — open `index.html` directly in a browser or serve it with a static server.

---

## How to run

From the `trivia/` directory:

- Open `index.html` directly in your browser (double-click or `File → Open`), or
- Serve over HTTP for a slightly more realistic environment:
  ```
  # install flask on your pc
  # from the trivia directory
  flask run
  # then open http://localhost:8000
  ```

---
Developed by Enzo C. Consulo as part of Harvard’s CS50 coursework (2025).
