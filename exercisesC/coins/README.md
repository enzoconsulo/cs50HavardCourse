# CS50 C PROJECTS: CASH & CREDIT

**Greedy Cash Change & Credit Card Validator in C (CS50 Pset 1)**

## Exercise Prompts
- Cash (`coins.c`): https://cs50.harvard.edu/x/2021/psets/1/cash/  
- Credit (`coinsCredit.c`): https://cs50.harvard.edu/x/2021/psets/1/credit/

## Features
### Cash (`coins.c`)
- Prompt user for a non-negative dollar amount (float)  
- Convert dollars to cents with `round()`  
- Compute minimum number of coins (25¢, 10¢, 5¢, 1¢) using a greedy algorithm  

### Credit (`coinsCredit.c`)
- Prompt user for a credit card number (long)  
- Implement Luhn’s algorithm to validate the number  
- Identify card type (AMEX, VISA, MASTERCARD) or report INVALID  

## Technologies
- C (ISO C11)  
- CS50 Library (`get_float`, `get_long`)  
- `<math.h>` for `round()`  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)  

## What I Learned
- **Input Validation:** `do…while` loops for floats and long ints  
- **Greedy Algorithms:** always choose the largest coin first  
- **Luhn’s Algorithm:** digit manipulation and checksum logic  
- **Rounding & Casting:** accurate float-to-int conversion  
- **Control Flow:** nested loops, conditionals, and switch statements  

## Files
```
coins/
├─ coins.c # Cash change (greedy algorithm)
├─ coinsCredit.c # Credit card validator (Luhn’s algorithm)
└─ README.md # This file
```

## Compile & Run
```
# Compile
clang -o cash   coins.c       -lcs50 -lm
clang -o credit coinsCredit.c -lcs50 -lm
# or
make cash
make credit

# Execute
./cash     # prints min coins
./credit   # prints card type or INVALID

##Example:

$ ./cash
Change owed: 0.41
4

$ ./credit
Number: 378282246310005
AMEX
```
## Notes
- Link math library with -lm for round()
- Tested on Ubuntu 22.04 & macOS Monterey
- All I/O via terminal

— Enzo C. Consulo, CS50 2025
