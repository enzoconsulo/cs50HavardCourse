# CS50 Harvard Course Exercises

This repository contains my solutions to the CS50 problem sets and labs in C, organized by exercise directory. Each folder includes a `README` with detailed instructions, features, and what I learned.

## 📂 Directory Structure

```
exercisesC/
├─ mario/               # Half and full pyramid generators (CS50 Pset 1)
├─ PopulationGrowth/    # Population growth simulation (CS50 Pset 1)
├─ coins/               # Cash change & Credit card validator (CS50 Pset 1)
├─ scrabble/            # Scrabble scoring lab (CS50 Lab 2)
├─ criptografy/         # Caesar & Substitution ciphers (CS50 Pset 2)
├─ readability/         # Text readability calculator (CS50 Pset 2)
└─ election/            # Voting simulations (CS50 Pset 3)
```

## 📖 Exercises Overview

* [Mario (Pset 1)](exercisesC/mario)
  Implements half-pyramid and full-pyramid generators in C. Covers nested loops, input validation, and text-based graphics.

* [PopulationGrowth (Pset 1)](exercisesC/PopulationGrowth)
  Simulates population growth over years with +10% births and −5% deaths. Covers loops, floating-point arithmetic, and casting.

* [Coins & Credit (Pset 1)](exercisesC/coins)

  * **coins.c**: Greedy algorithm for minimum coin change.
  * **coinsCredit.c**: Credit card validator using Luhn’s algorithm.
    Covers greedy strategies, integer math, checksum algorithms, and command-line I/O.

* [Scrabble (Lab 2)](exercisesC/scrabble)
  Calculates Scrabble word scores for two players. Covers arrays mapping, string traversal, and ASCII functions.

* [Cryptography (Pset 2)](exercisesC/criptografy)

  * **caesar.c**: Implements Caesar cipher encryption.
  * **substitution.c**: Implements substitution cipher with a provided key.
    Covers command-line argument parsing, ASCII arithmetic, and modular code design.

* [Readability (Pset 2)](exercisesC/readability)
  Computes the Coleman-Liau index for text readability. Covers text analysis, character classification, and floating-point calculations.

* [Election (Pset 3)](exercisesC/election)

  * **plurality.c**: First-past-the-post voting.
  * **runoff.c**: Instant-runoff voting.
  * **tideman.c**: Ranked-pairs (Tideman) voting.
    Covers arrays, preference matrices, cycle detection, and various voting algorithms.

---

*Developed by Enzo C. Consulo as part of Harvard’s CS50 curriculum (2025).*
