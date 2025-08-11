# MARIO C PROJECT

**Console-based Pyramid Generators in C (CS50 Pset 1)**

Seguindo a especificação CS50 Mario:  
- Half-pyramid: https://cs50.harvard.edu/x/psets/1/mario/less/  
- Full-pyramid: https://cs50.harvard.edu/x/psets/1/mario/more/  

## Features
- **Half-pyramid** (`mario.c`): right-aligned, height 1–8  
- **Full-pyramid** (`mario_more.c`): double, gap de 2 espaços, height 1–8  
- Input validation until is valid

## Technologies
- C (ISO C11)  
- CS50 Library (`get_int`)  
- GCC/Clang, Unix-like (Linux, macOS, WSL)

## What I Learned
- **Validação de entrada** com `do…while`  
- **Loops aninhados** para espaços e `#`  
- **Modularização** em funções  
- **Linkagem** de bibliotecas (`-lcs50`)

## Files
```
- mario.c        – half-pyramid (right-aligned)
- mario_challenge.c  – full-pyramid (double with 2-space gap)
```
## Compile & Run
```
## Compile
clang -o mario      mario.c      -lcs50
clang -o mario_challenge mario_challenge.c -lcs50
## or:
make mario
make mario_challenge

## Usage
./mario       # enter height 1–8, prints right-aligned pyramid
./mario_challenge  # enter height 1–8, prints double pyramid
```
## Notes
- Validates input with a do…while loop (1 ≤ n ≤ 8).
- Uses nested for-loops to print spaces and ‘#’.
- Requires CS50 library (-lcs50).

— Enzo C. Consulo, CS50 2025
