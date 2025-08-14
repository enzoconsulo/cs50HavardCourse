# MARIO (Python) PROJECT

**Console-based Pyramid Generators in Python (CS50 Pset 6 — Mario Less & More)**

This folder contains two Python solutions for CS50’s Mario problems: the **less** (half-pyramid) and **more** (full-pyramid) variants.

## Features

- **Half-pyramid (`mario_less.py`)**
  - Right-aligned pyramid of `height` rows (1 ≤ height ≤ 8).
  - Re-prompts until valid integer in range.
- **Full-pyramid (`mario_more.py`)**
  - Symmetric double pyramid with a two-space gap between halves (1 ≤ height ≤ 8).
  - Re-prompts until valid integer in range.

## Technologies

- Python 3.8+ (works with 3.x)  
- No external dependencies required (pure stdlib) — optionally CS50 Python library if you prefer `get_int()`.

## What I learned

- **Input validation in Python:** using `while` and `try/except` to guard against non-integer input.  
- **Looping & formatting:** building rows with `str` multiplication and concatenation for clean console output.  
- **Portable scripts:** writing command-line friendly Python programs (works on Linux/macOS/Windows).  
- **Small UX touches:** clear prompts and robust re-prompting behavior to match CS50 spec.

## Project structure
```
mario/
├─ mario_less.py # half-pyramid (right-aligned)
├─ mario_more.py # full-pyramid (double with 2-space gap)
└─ README.md # this file
```

## How to run

From the `exercisesPython/mario/` folder:

```
# Run half-pyramid (less comfortable)
python3 mario_less.py

# Run full-pyramid (more comfortable)
python3 mario_more.py
```
## Usage examples

Half-pyramid:
```
$ python3 mario_less.py
Height: 4
   #
  ##
 ###
####


Full-pyramid:

$ python3 mario_more.py
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
## Notes & tips
- If you want to use CS50’s helper get_int, install cs50 (pip install cs50) and replace input() + int() handling.
- Keep height range check consistent with CS50 (1 through 8) to match autograder expectations.
- For portability, test scripts with python3 in your target environment (CS50 IDE, local Linux, WSL, or macOS).