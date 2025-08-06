# ELECTION C PROJECT

**Console-based Voting Simulations in C (CS50 Pset 3)**

## Exercise Prompts
- Plurality: https://cs50.harvard.edu/x/2021/psets/3/plurality/  
- Runoff:     https://cs50.harvard.edu/x/2021/psets/3/runoff/  
- Tideman:    https://cs50.harvard.edu/x/2021/psets/3/tideman/  

## Features
- **plurality.c**  
  - Implements first-past-the-post voting.  
  - Counts votes for each candidate; prints winner(s).  
- **runoff.c**  
  - Implements instant-runoff voting.  
  - Repeatedly eliminates last-place candidate(s) until majority winner or tie.  
- **tideman.c**  
  - Implements Tideman (ranked pairs) voting.  
  - Records preferences, sorts pairs by strength, locks pairs without cycles, prints winner.  

## Technologies
- C (ISO C11)  
- CS50 Library (`get_string`, `get_int`)  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I Learned
- **Arrays & Matrices:** tracking vote tallies and preference graphs  
- **Algorithms:**  
  - Counting & sorting (plurality, pair-strength sorting)  
  - Graph algorithms to detect cycles (Tideman)  
  - Elimination loops (runoff)  
- **Data Structures:** structs for candidates and pairs  
- **Control Flow:** nested loops, recursion/cycle checking  
- **Modularization:** breaking each voting method into clear functions  

## Structure
```
election/
├─ plurality.c # first-past-the-post voting
├─ runoff.c # instant-runoff voting
├─ tideman.c # ranked-pairs (Tideman) voting
└─ README.md # this file
```
```
## Compile & Run
# Compile all
clang -o plurality plurality.c -lcs50
clang -o runoff    runoff.c    -lcs50
clang -o tideman   tideman.c   -lcs50

# Or, with Makefile:
make plurality
make runoff
make tideman

# Execute examples
./plurality Alice Bob Charlie
./runoff    Alice Bob Charlie
./tideman   Alice Bob Charlie
```
## Notes
- Uses CS50’s -lcs50 library for I/O
- Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)
- All I/O via terminal; no GUI

— Enzo C. Consulo, CS50 2025
