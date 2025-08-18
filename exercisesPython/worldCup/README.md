# WORLD CUP (Python) PROJECT

**World Cup tournament simulator in Python (CS50 Lab 6 — World Cup)**

Following CS50 Lab 6 specification:  
https://cs50.harvard.edu/x/2021/labs/6/

This folder contains a program that reads a CSV of teams with ratings, simulates many tournaments using pairwise game probabilities derived from ratings, and estimates each team’s probability of winning.

---

## Features

* Loads teams and integer ratings from a CSV (`team,rating`).
* Simulates single-elimination tournaments by repeatedly pairing teams and simulating games.
* Uses a rating-based probability function (Elo-like):  
  `P(team A beats team B) = 1 / (1 + 10 ** ((rating_B - rating_A) / 600))`  
  (same formula used in the CS50 lab).
* Runs many simulations (e.g., 1,000) and reports each team’s estimated chance of winning as a percentage.
* Optional: reproducible runs with a random seed, configurable number of simulations for speed/accuracy trade-off.

---

## Technologies

* Python 3.8+ (works with modern 3.x)
* Standard library: `csv`, `random`, `sys`, `collections`
* No external dependencies

---

## What I learned

* **Probability modelling:** implementing an Elo-style probability formula to map ratings to win probabilities.  
* **Monte Carlo simulation:** running many randomized tournaments to approximate win probabilities.  
* **Data structures:** using lists/dictionaries to represent teams and counts; shuffling/pairing teams for rounds.  
* **CSV handling:** reading structured input with `csv.DictReader`.  
* **Performance trade-offs:** balancing number of simulations for statistical confidence vs runtime; using efficient in-place operations and minimal copying.  
* **Reproducibility & debugging:** using `random.seed()` for repeatable experiments and printing intermediate state for debugging.

---

## Project structure
```
worldCup/
├─ tournament.py # main simulation script (reads CSV, runs simulations, prints results)
├─ README.md # this file
├─ teams.csv # optional example CSV (team,rating)
└─ results/ # (optional) sample outputs or logs
```

## How to run

From the `exercisesPython/worldCup/` folder:

```
# Basic usage:
python3 tournament.py 2018m.csv

```
- 2018m.csv — CSV file where each row contains team_name,rating with integer rating.
Example output (summary):
```
Simulating 1000 tournaments...
Brazil: 34.1% chance of winning
France: 18.7% chance of winning
Germany: 10.3% chance of winning
...
```
Developed by Enzo C. Consulo as part of CS50 coursework.