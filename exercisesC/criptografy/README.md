# CRYPTOGRAPHY C PROJECT

**Console-based Caesar & Substitution Ciphers in C (CS50 Pset 2)**

## Exercise Prompts
- Caesar cipher:     https://cs50.harvard.edu/x/2021/psets/2/caesar/  
- Substitution cipher: https://cs50.harvard.edu/x/2021/psets/2/substitution/  

## Features
### Caesar (`caesar.c`)
- Encrypts plaintext by shifting each letter by a key (0–25)  
- Preserves case; non-alphabetic characters remain unchanged  
- Validates command-line argument (single integer key)  

### Substitution (`substitution.c`)
- Encrypts plaintext using a 26-letter key provided as CLI argument  
- Validates key (26 unique alphabetical characters)  
- Preserves case; non-alphabetic characters remain unchanged  

## Technologies
- C (ISO C11)  
- CS50 Library (`get_string`, `get_int`)  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)  

## What I Learned
- **Command-line arguments:** parsing `argv[]` and input validation  
- **ASCII arithmetic:** shifting letters within ‘A’–‘Z’ / ‘a’–‘z’ using `% 26`  
- **String iteration & indexing:** mapping plaintext to cipher text  
- **Error handling:** exiting with usage messages for invalid keys  
- **Modularization:** separating validation and encryption logic into functions  

## Structure
criptografy/
├─ caesar.c # implements Caesar cipher
├─ substitution.c # implements Substitution cipher
└─ README.txt # this file

## Compile & Run

# Compile
clang -o caesar       caesar.c       -lcs50
clang -o substitution substitution.c -lcs50

# Or with Makefile:
make caesar
make substitution

# Execute Caesar
./caesar 3
plaintext:  Hello, World!
ciphertext: Khoor, Zruog!

# Execute Substitution
./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  Hello, World!
ciphertext: Jrssb, Ybwsp!

## Notes
-Both programs link CS50’s library with -lcs50
-Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)
-All I/O via terminal; no GUI

— Enzo C. Consulo, CS50 2025
