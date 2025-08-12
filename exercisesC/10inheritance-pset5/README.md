# INHERITANCE C PROJECT

**Simulate genetic inheritance of blood type in C (CS50 Lab 5 — “Inheritance”)**

Following CS50 Lab 5 specification:  
https://cs50.harvard.edu/x/2021/labs/5/

## Features
- Builds a family tree with `N` generations (configurable).  
- Each person has two parents and two alleles representing blood type.  
- Randomly generates parental alleles consistent with Mendelian inheritance rules.  
- Prints family tree with indentation per generation.  
- Frees all allocated memory (no leaks).

## Technologies
- C (ISO C11)  
- Standard libraries: `<stdio.h>`, `<stdlib.h>`, `<time.h>`, `<string.h>`  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I Learned
- **Dynamic memory allocation:** using `malloc()`/`free()` to create and destroy a tree-shaped set of structs.  
- **Structs & pointers:** representing each person with a struct containing parent pointers and allele data.  
- **Recursion:** creating, printing and freeing generations with recursive functions (`create_family`, `print_family`, `free_family`).  
- **Randomization & probability:** seeding `rand()` with `time(NULL)` and simulating allele inheritance.  
- **Memory safety:** ensuring every `malloc`ed block is `free`d and avoiding use-after-free.  
- **Testing strategies:** running multiple trials and using tools like `valgrind` to check for leaks.

## Project Structure
```
inheritance/
├─ inheritance.c # main implementation (create_family, print_family, free_family)
└─ README.md # this file
*(Consider `inheritance.c` as the program filename per your request.)*
```

## Compile & Run
```
# Compile
clang -o inheritance inheritance.c
# or with GCC
gcc -o inheritance inheritance.c

# Run (example): create 3 generations
./inheritance 3
```
## Typical usage
- The program may accept an integer argument for number of generations (e.g., ./inheritance 3).
- If the program uses interactive input, follow the on-screen prompt(s).

## Example output (simplified)
```
Generation 0, Person 0: alleles: A O
Generation 1, Person 0: alleles: A A
  Generation 2, Person 0: alleles: A O
  Generation 2, Person 1: alleles: O O
Generation 1, Person 1: alleles: A O
  Generation 2, Person 2: alleles: A O
  Generation 2, Person 3: alleles: A A
```
## Notes & Tips
- Seed the RNG once (srand(time(NULL))) in main.
- When implementing create_family, allocate a person and recursively allocate its parents until base generation.
- For base-generation parents (no parents), assign alleles randomly from the allele set ({'A','B','O'}) per lab spec.
- Inherit alleles from parents by randomly picking one allele from each parent.
- Use valgrind ./inheritance ... to verify there are no memory leaks.
- Keep recursion depth reasonable—large generation counts create exponential numbers of person structs.

Developed by Enzo C. Consulo as part of Harvard’s CS50 curriculum (2025).
