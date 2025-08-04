# POPULATION GROWTH C PROJECT

**Console-based Population Growth Simulation in C (CS50 Pset 1)**

Inspired by the CS50 Population specification:  
https://cs50.harvard.edu/x/psets/1/population/

## Features
- Prompts for **starting population** ≥ 9  
- Prompts for **ending population** ≥ starting value  
- Calculates **years** required for population to reach or exceed target, assuming:
  - +10% growth per year from adult mice  
  - −5% loss per year from aging  

## Technologies
- C (ISO C11)  
- CS50 Library (`get_int`)  
- GCC/Clang, Unix-like (Linux, macOS, WSL)

## What I Learned
- **Input validation** with `do…while` loops  
- **Floating-point arithmetic** and casting  
- **While-loops** for iterative calculations  
- **Modular code**: separating I/O and logic into clear steps  

## Structure
PopulationGrowth/
├─ population.c # population growth simulation
└─ README.txt # this file

## Compile & Run

# Compile
clang -o population population.c -lcs50
 or
make population

# Execute
./population
Enter a starting size (integer ≥ 9).

Enter an ending size (integer ≥ start).

Program outputs the number of years until target reached.

— Enzo C. Consulo, CS50 2025
