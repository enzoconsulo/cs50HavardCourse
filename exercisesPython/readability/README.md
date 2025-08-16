# READABILITY (Python) PROJECT

**Text Readability (Coleman–Liau index) in Python (CS50 Pset 6 — Readability)**

Following CS50 Readability specification:  
https://cs50.harvard.edu/x/2021/psets/6/readability/

This folder contains **two versions** of the Readability solution:

- `readability_simpleversion.py` — a compact solution that counts letters, words and sentences on the fly and computes the Coleman–Liau index (matches the CS50 spec).
- `readability.py` — a more feature-rich implementation (your extended version) that additionally tokenizes the input into lists (vectors) of words and sentences. That extra work enables extended analysis (word frequencies, per-sentence statistics, debugging, etc.) and was implemented for learning purposes.

---

## Features

### `readability_simpleversion.py` (simple)
* Prompts the user for a block of text.
* Counts:
  * letters (alphabetic characters),
  * words (based on whitespace/token boundaries),
  * sentences (periods `.` / exclamation `!` / question `?`).
* Generates grade level by Coleman–Liau index:
  * index = 0.0588 * L - 0.296 * S - 15.8
    * where L = average letters per 100 words, S = average sentences per 100 words.
  * Prints grade level as: `Before Grade 1`, `Grade X`, or `Grade 16+`.

### `readability.py` (enhanced)
* All of the above **plus**:
* Tokenizes the text into a `words` list and a `sentences` list.
* Stores each word and each sentence for additional inspection.
* Optionally prints or returns extra stats (e.g., average word length, word frequency, longest sentence) if you enable those debug/analysis hooks.
* Useful for experiments (e.g., alternate definitions of "word" or "sentence", different tokenizers, or adding more readability metrics).

---

## Technologies

* Python 3.8+ (works with any modern 3.x)
* No external dependencies (pure stdlib). If you like, you can swap in `nltk` or other tokenizers later for more sophisticated splitting.

---

## What I learned / Why the two versions

* **Counting basics (simple):** how to walk a string and count letters/words/sentences efficiently without extra memory — this matches the CS50 autograder expectations.
* **Tokenization & data structures (enhanced):** storing words and sentences in lists enables deeper analysis (frequency distributions, statistics per sentence, richer debugging). It also teaches string manipulation, splitting heuristics and edge-case handling.
* **Trade-offs:** simple version is memory-light and sufficient for the assignment; enhanced version uses more memory but is far more extensible for experiments and learning.
* **Edge-case handling:** punctuation, apostrophes, abbreviations (e.g., `e.g.`), and hyphenated words can change counts depending on tokenization strategy — the enhanced version lets you experiment with those rules.

---

## Project structure
```
readability/
├─ readability_simpleversion.py # compact, CS50-focused solution
├─ readability.py # extended/educational version with tokenization
└─ README.md # this file
```

## Example
```
$ python3 readability_simple.py
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

## Notes, tips & possible improvements

- Word counting: The simplest approach is to count spaces+1. The enhanced version uses str.split() (or regex) to get more accurate tokens — this helps when texts include multiple spaces or newline separators.
- Sentence detection: CS50's recommended rule is to count ., ?, and !. The enhanced version can split on those characters to build sentence strings, but be careful with abbreviations (Dr., e.g.) which will be counted as sentence terminators unless you add logic to detect them.
- Non-ASCII letters: If you plan to process multilingual text, use Unicode-aware checks (e.g., str.isalpha() works for many scripts in Python 3, but rules may differ).
- Rounding: follow CS50 spec for rounding the final index (round to nearest integer using round() and then print Grade X, with round() semantics matching the autograder expectations).
- Testing: test with edge inputs:
- Empty string
- One very long sentence, no punctuation
- Texts with multiple spaces/newlines
- Texts with many punctuation marks
- Extending the enhanced version: with your tokenized lists you can easily implement:
  * word frequency (top N words),
  * average sentence length in words,
- Flesch reading ease or other metrics,
improved tokenizers (use re to split on word boundaries).

Developed by Enzo C. Consulo as part of CS50 coursework. The readability.py version was implemented intentionally with tokenization to practice list-based analysis beyond the basic assignment requirements.