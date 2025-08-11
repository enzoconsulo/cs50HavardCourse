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
├─ election/            # Voting simulations (CS50 Pset 3)
├─ filter-less/         # BMP image filters (CS50 Pset 4)
├─ recover/             # JPEG forensic recovery (CS50 Pset 4)
└─ volume/              # Audio volume modifier (CS50 Lab 4)
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
  Computes the Coleman‑Liau index for text readability. Covers text analysis, character classification, and floating-point calculations.

* [Election (Pset 3)](exercisesC/election)

  * **plurality.c**: First-past-the-post voting.
  * **runoff.c**: Instant-runoff voting.
  * **tideman.c**: Ranked-pairs (Tideman) voting.
    Covers arrays, preference matrices, cycle detection, and various voting algorithms.

* [Filter-Less (Pset 4)](exercisesC/filter-less)
  Applies basic image filters (grayscale, sepia, reflect, blur) to BMPs using `helpers.c`. Covers file I/O with BMP headers, pixel manipulation, edge-case handling, and image processing logic.

* [Recover (Pset 4)](exercisesC/recover)
  Scans a forensic image for JPEG signatures and recovers each photo block-by-block. Covers binary file I/O, header detection, dynamic file creation, and buffer management.

* [Volume (Lab 4)](exercisesC/volume)
  Modifies the amplitude of a WAV file by a factor provided by the user. Covers WAV header parsing, reading/writing 16-bit samples, scaling and clipping sample values, and binary file I/O.

## 📚 What each Pset represents in CS50

* **Pset 1 — Foundations (C & basic programming concepts)**
  Introduces C syntax, conditionals, loops, functions, and console I/O. Early problems (Mario, Cash, Population) focus on algorithmic thinking, input validation, and basic data manipulation.

* **Pset 2 — Strings, Arrays & Data Processing**
  Builds on C fundamentals with string handling, arrays, command-line arguments, and text processing (e.g., Caesar, Substitution, Readability). Emphasizes careful character-level logic and edge-case handling.

* **Pset 3 — Algorithms & Data Structures**
  Introduces more advanced problem solving: preference matrices, sorting, graph concepts, and cycle detection (e.g., Plurality, Runoff, Tideman). Focuses on building correct, efficient algorithms and using structs/2D arrays.

* **Pset 4 — Memory & File I/O / Systems Programming**
  Moves into binary file manipulation, pointers, and memory layout. Labs and problems (Filter, Recover, Volume) teach how to read/write file formats (BMP, WAV), manipulate raw bytes, and manage buffers safely.

---

*Developed by Enzo C. Consulo as part of Harvard’s CS50 curriculum (2025).*
