# SCRABBLE C PROJECT

**Console-based Scrabble Scoring in C (CS50 Lab 2)**

Following CS50 Lab 2 specification:  
https://cs50.harvard.edu/x/2021/labs/2/

## Features
- Prompts two players for a word each  
- Computes Scrabble score using standard letter values (A=1, B=3, …, Z=10)  
- Ignores non-alphabetic characters  
- Announces winner or declares a tie

## Technologies
- C (ISO C11)  
- CS50 Library (`get_string`)  
- GCC/Clang, Unix-like (Linux, macOS, WSL)

## What I Learned
- **Arrays & Mapping:** storing letter values in an indexed array  
- **String Processing:** iterating over `char *` and using `toupper()`  
- **Control Flow:** summing scores with loops and conditionals  
- **Modular Code:** separating score calculation into its own function

## Structure
```
scrabble/
├─ scrabble.c # main program and scoring logic
└─ README.txt # this file
```
## Compile & Run
```
# Compile
clang -o scrabble scrabble.c -lcs50
# or, with Makefile:
make scrabble

# Execute
./scrabble

## Example:
$ ./scrabble
Player 1: HELLO!
Player 2: world?
Player 1 wins!
```
## Notes
- Uses -lcs50 to link CS50’s library
- Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)
- All I/O via terminal; no GUI

— Enzo C. Consulo, CS50 2025
