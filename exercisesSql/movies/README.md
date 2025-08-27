# MOVIES (SQL) PROJECT

**SQL queries on a movies database (CS50 Pset 7 — Movies)**

Following CS50 Problem Set 7 specification:
[https://cs50.harvard.edu/x/2021/psets/7/movies/](https://cs50.harvard.edu/x/2021/psets/7/movies/)

This folder contains SQL exercises against a provided `movies.db` (a SQLite database with movie data such as titles, years, directors, genres, cast, and ratings). Each problem asks for a single SQL query that returns specific results (one per file).

---

## Files / Tasks

Typical problem files for this pset include queries such as:

* `1.sql` — list titles of all movies (single-column result)
* `2.sql` — list titles ordered by year or rating
* `3.sql` — top N movies by box office or rating
* `4.sql` — movies matching a genre or director
* `5.sql` — aggregate queries (e.g., average rating per director)
* `6.sql` — find actors who co-starred with a given actor
* `7.sql` — advanced joins and subqueries (e.g., directors with highest average ratings)

(Adjust filenames to match your repository. Each `.sql` file should contain only the single SQL query required for that problem.)

## How to run (locally)

1. Open a terminal and change into this folder (where `songs.db` lives):

```bash
cd exercisesSql/songs
```

2. Start SQLite on the provided database:

```bash
sqlite3 songs.db
```

3. Inspect schema to understand tables/columns:

```
sqlite3> .schema
sqlite> *tables*
```


## Testing & Submission

```
user> cat <x.sql> || <the directory to db>
sqlite3> *solution*
```

---

## What to focus on

* **JOINS:** Many queries require joining multiple tables (e.g., `movies`, `directors`, `actors`, `roles`, `genres`). Understand foreign keys and how records relate.
* **Aggregates & GROUP BY:** Use `COUNT()`, `AVG()`, `SUM()` and `GROUP BY` when calculating totals or averages per director/genre/year.
* **Filtering & WHERE:** Use `WHERE` and `HAVING` (for aggregate filters) to narrow results.
* **Sorting & LIMIT:** `ORDER BY` with `ASC`/`DESC` and `LIMIT` for top-N queries.
* **Subqueries:** Useful for multi-step logic (e.g., find movies whose rating exceeds the average rating of a director).
* **String functions:** `LIKE`, `instr()`, and `LOWER()` help with case-insensitive matching or pattern searches.
* **Performance notes:** In large datasets, indexes help — but for this lab, focus on correctness and clear SQL.



## What I learned

* **Relational design & JOIN patterns:** composing queries across normalized tables to reconstruct complex relationships (e.g., which actors appear in which director’s films).
* **Aggregation & grouping:** computing averages, counts, and other statistics grouped by director, year, or genre.
* **Subqueries & filtering:** writing nested queries to express multi-step logic without temporary tables.
* **SQLite specifics:** small differences in functions and types compared to other RDBMSs; `.schema`, `.headers on`, and `.mode column` are handy for debugging.
* **Result formatting:** ensure queries return exactly the columns and order required by the problem descriptions.

---

*Developed by Enzo C. Consulo as part of Harvard’s CS50 coursework (2025).*
