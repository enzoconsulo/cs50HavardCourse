# DNA (Python) Project

**DNA sequence matcher in Python (CS50 Pset 6 — DNA)**

Following CS50 Pset 6 specification:  
https://cs50.harvard.edu/x/2021/psets/6/dna/

This folder contains an implementation (`dna.py`) that reads a CSV database of STR counts and a DNA sequence (.txt) and identifies the person whose STR profile matches the longest consecutive runs found in the DNA sequence. The version here also stores intermediate results (words/STRs and matches) in lists for easier analysis and debugging.

---

## Features

* Reads a CSV database (first row: column names `name, STR1, STR2, ...`) using `csv.DictReader`.
* Reads a DNA sequence file into memory as a string.
* For each STR from the CSV header, computes the **longest consecutive run** of that STR in the DNA sequence using a `longestMatch` recursive function.
* Compares the vector/list of computed STR counts against each person in the CSV, printing the matching `name` if there is an exact match, otherwise prints `No match`.
* (Extended) Stores STR tokens and computed matches in lists for inspection (useful for debugging, extra stats or experiments).

---

## Project structure

```
dna/
├─ dna.py # main implementation (reads files, computes longest_match, finds matching profile)
├─ README.md # this file
├─ databases/ # (optional) CSV example files used for testing (e.g., small.csv, large.csv)
└─ sequences/ # (optional) DNA sequence text files for testing (e.g., 1.txt, 2.txt)
```

---

## How to run

From `exercisesPython/dna/`:

```
python3 dna.py data.csv sequence.txt
```
- data.csv — CSV file with header name,STR1,STR2,... and rows with integer STR counts.

- sequence.txt — text file containing a string (A, C, G, T) representing a DNA sample.

### Example:
```
$ python3 dna.py databases/small.csv sequences/1.txt
Bob
```
If no profile matches the computed STR counts:
```
$ python3 dna.py databases/small.csv sequences/1.txt
No match
```

## Implementation details (typical structure)
1. Your dna.py likely follows this flow:
2. Argument check — verify len(sys.argv) == 3.
3. Load database — use csv.DictReader to read rows into a list of dicts and capture the STR column names from the header.
4. Read sequence — open the sequence file and read() it into a single string.
5. Compute matches — for each STR:
  - call longest_match(sequence, subsequence) to compute the longest run of consecutive repeats;
  - collect results in a list (e.g., matches = [17, 22, 19]).
6. Compare with database — iterate each person (row) and compare the row's STR counts (converted to int) with matches; if equal, print the name and exit.
7. No matches — print No match if none equal.

## What I learned
- CSV parsing & DictReader: read headers and rows in a way that maps STR labels to counts; easier access to values by column name.
- String algorithms: implemented longest_match (sliding-window or position-based scanning) to compute the longest consecutive repeat of a short substring inside a long string reliably and efficiently.
- List/vector usage: storing STR names and computed counts in lists makes comparisons and debugging straightforward; enables extra analytics (e.g., frequency, per-STR stats).
- Type handling: CSV values are strings — careful conversion to int is required before comparison.
- Robust I/O & CLI: validated command-line arguments and handled file I/O gracefully.
- Testing & correctness: validated results with example databases and sequence files from CS50; edge cases include empty sequences, STRs not present at all, and overlapping matches.
- Performance considerations: longest_match must be efficient since sequence files may be large — avoid overly expensive repeated substring operations.

---

*Developed by Enzo C. Consulo as part of Harvard’s CS50 curriculum (2025).*