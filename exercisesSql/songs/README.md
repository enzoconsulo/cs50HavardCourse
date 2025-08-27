# SONGS (SQL) PROJECT

**SQL queries on a songs database (CS50 Lab 7 — Songs)**

Following CS50 Lab 7 specification:
[https://cs50.harvard.edu/x/2021/labs/7/](https://cs50.harvard.edu/x/2021/labs/7/)

This folder contains SQL exercises against a provided `songs.db` (a SQLite database with Spotify-derived data for the top 100 streamed songs of 2018). Your task is to write single SQL queries (one per problem file) that answer questions about songs and artists.

---

## Files / Tasks

You should provide one SQL query per problem file. Typical filenames in this lab are:

* `1.sql` — List names of all songs (single-column result).
* `2.sql` — List names of all songs ordered by increasing tempo.
* `3.sql` — List names of the top 5 longest songs (descending by duration).
* `4.sql` — List names of songs with danceability, energy, and valence > 0.75.
* `5.sql` — Return the average energy of all songs (single value).
* `6.sql` — List names of songs by *Post Malone* (do not assume `artist_id`).
* `7.sql` — Return average energy of songs by *Drake* (do not assume `artist_id`).
* `8.sql` — List names of songs that feature other artists (song names that include `feat.`).

---

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

## What I learned

* **Reading schemas:** using `.schema` in `sqlite3` to discover table structures and available columns.
* **SELECT basics:** selecting columns, filtering with `WHERE`, and ordering with `ORDER BY`.
* **Aggregation:** computing averages using `AVG()` and returning single-value results.
* **JOINs / relationships:** joining `songs` and `artists` tables via `artist_id` to query by artist name without assuming numeric IDs.
* **String filtering:** using `LIKE` (or `instr()` / other functions) to find song names that include `feat.`.
* **Limiting & sorting:** using `ORDER BY` + `LIMIT` to return top-N results (e.g., top 5 longest songs).
* **Precision & output:** ensuring queries return only the necessary column(s) and in the format expected by the lab’s autograder.

---

## Notes & tips

* Always avoid hard-coding `id` values; match on `artist.name` with a `JOIN` instead.
* Use `ROUND()` or appropriate formatting only when the problem requires a specific numeric format. Otherwise return the raw aggregate value.
* Preview results interactively in `sqlite3` while developing queries to ensure exact expected output.

---

*Developed by Enzo C. Consulo as part of Harvard’s CS50 coursework (2025).*
