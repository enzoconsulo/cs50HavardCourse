# READABILITY C PROJECT

Console-based Text Readability Calculator in C (CS50 Pset 2)

Exercise prompt (enunciado):  
https://cs50.harvard.edu/x/2021/psets/2/readability/

## Features
- Prompts user for a block of text  
- Counts letters, words, and sentences  
- Computes Coleman-Liau index:  
  `index = 0.0588 * L – 0.296 * S – 15.8`  
  where L = average letters per 100 words, S = average sentences per 100 words  
- Prints grade level: “Grade X”, “Before Grade 1” or “Grade 16+”

## Technologies
- C (ISO C11)  
- CS50 Library (`get_string`)  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I Learned
- **String traversal:** iterating over `char *` to classify characters  
- **Character classification:** using `isalpha()` and `ispunct()`  
- **Counting logic:** tracking word and sentence boundaries  
- **Floating-point math & rounding:** computing and rounding Coleman-Liau index  
- **Conditional formatting:** handling edge cases for very high/low grades

## Structure
```
readability/
├─ readability.c # implements text analysis and index calculation
└─ README.txt # this file
```

## Compile & Run
```
# Compile
clang -o readability readability.c -lcs50
# or, if using CS50’s Makefile:
make readability

# Execute
./readability
1. Enter your text when prompted.
2. View the grade level output.
```
## Notes
- No additional libraries beyond CS50 required
- Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)
- All I/O via terminal; no GUI

— Enzo C. Consulo, CS50 2025
