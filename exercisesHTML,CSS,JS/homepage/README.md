# HOMEPAGE (HTML, CSS & JS) PROJECT

**Personal homepage for CS50 Pset 8 — “Homepage”**

Following CS50 Pset 8 specification:  
https://cs50.harvard.edu/x/2021/psets/8/

This folder contains a small static personal homepage (two pages) implemented with HTML, CSS and Bootstrap (via CDN). The README below describes exactly what is in the folder and how the files behave.

---

## What’s in this folder (exact)

* `index.html` — main page (welcome, photo, links, small GIF, footer with links).
* `whoAmI.html` — secondary page with a short bio and a “Back to Home” link.
* `styles.css` — custom CSS (background color, title styling, bio text size).
* `DSC00066.JPG` — personal photo referenced by `index.html` (must be present in folder).
* `scratch-just-walk-away.gif` — small GIF referenced by `index.html`.

---

## Features / Behavior (what the site actually does)

* Static, client-side pages only — no server code.  
* Uses Bootstrap 5 from CDN (CSS and bundle JS) for base styling.  
* `index.html` shows:
  * Title and subtitle,
  * Photo (`DSC00066.JPG`) with `alt="My photo"`,
  * Short description and two external links (currently `github.com/enzoconsulo` and `linkedin.com/in/enzoconsulo/` — note: missing `https://`),
  * Small animated GIF (`scratch-just-walk-away.gif`),
  * Footer with internal link to `whoAmI.html` and two placeholder links.
* `whoAmI.html` shows a centered title and a bio paragraph block, plus a footer link back to `index.html`.  
* Styling in `styles.css`:
  * Page background: pale yellow,
  * `#toptitle` background: orange,
  * `#biotext` font-size set to `large`.

---

## How to run / preview

No build required. Two options:

* Open `index.html` directly in your browser (double-click the file).  
* Or serve the folder with a tiny static server for a more realistic environment:

```bash
#  install flask on your pc
# from the homepage directory
flask run
# then open: http://localhost:8000/index.html

---
Developed by Enzo C. Consulo as part of Harvard’s CS50 coursework (2025).