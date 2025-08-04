# MARIO C PROJECT

Console-based pyramid generators in C (CS50 Pset 1)

Inspired by the [CS50 Mario specification](https://cs50.harvard.edu/x/2025/psets/1/mario/).

## Files

- mario.c        – half-pyramid (right-aligned)
- mario_challenge.c  – full-pyramid (double with 2-space gap)

## Compile

clang -o mario      mario.c      -lcs50
clang -o mario_challenge mario_challenge.c -lcs50
->or:
make mario
make mario_challenge

## Usage
./mario       # enter height 1–8, prints right-aligned pyramid
./mario_challenge  # enter height 1–8, prints double pyramid

## Notes
Validates input with a do…while loop (1 ≤ n ≤ 8).

Uses nested for-loops to print spaces and ‘#’.

Requires CS50 library (-lcs50).

Tested on Ubuntu 22.04 / macOS with GCC 11 & Clang 14.

— Enzo C. Consulo, CS50 2025
