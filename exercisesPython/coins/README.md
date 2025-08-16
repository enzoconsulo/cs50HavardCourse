# COINS (Python) PROJECT

**Credit & Cash problems in Python (CS50 Pset 6 — Credit & Cash)**

Following CS50 specifications:  
- Credit: https://cs50.harvard.edu/x/2021/psets/6/credit/  
- Cash:   https://cs50.harvard.edu/x/2021/psets/6/cash/

> Note: folder is named `coins/` for historical reasons. This directory contains two Python solutions:
> - `credit.py` — Credit card validator (Luhn + card-type detection)  
> - `cash.py`   — Greedy coin change (minimum coins for change)

---

## Features

### Credit (`credit.py`)
- Prompts user for a credit card number (as string).  
- Validates number using **Luhn’s algorithm**.  
- Detects and prints card type: **AMEX**, **MASTERCARD**, **VISA**, or `INVALID`.  
- Handles arbitrary-length input safely by treating input as string.

### Cash (`cash.py`)
- Prompts user for a non-negative dollar amount (float).  
- Converts dollars to cents (using `round`) to avoid floating-point errors.  
- Uses a **greedy algorithm** to compute the minimum number of coins (25¢, 10¢, 5¢, 1¢).  
- Re-prompts until valid input (float ≥ 0).

---

## Technologies
- Python 3.8+  
- No external dependencies (pure stdlib). Optionally `cs50` Python package if you prefer `get_float()` / `get_int()` helpers.  
- Cross-platform (Linux, macOS, Windows).

---

## What I learned
- **String vs numeric handling:** keep credit numbers as strings for prefix/length checks; use numeric ops for Luhn checksum.  
- **Luhn’s algorithm implementation:** doubling every second digit from the right, summing digits (e.g., 12 → 1 + 2).  
- **Greedy algorithms:** coin-change greedy approach works for standard US coin set.  
- **Rounding & precision:** convert dollars to cents with `round(amount * 100)` to avoid FP inaccuracies.  
- **Input validation & robustness:** repeatedly prompt until valid input; sanitize non-digit characters for credit if needed.  
- **Test vectors:** validate using known card numbers and various change amounts (edge cases like $0.00, $0.41, etc.).

---

## Project structure
```
coins/
├─ credit.py # Credit card validator (Luhn + card type)
├─ cash.py # Greedy change calculator (dollars -> cents -> coins)
└─ README.md # this file
```


---

## How to run

```
# Run credit validator
python3 credit.py

# Run cash change calculator
python3 cash.py

Example sessions

Credit:

$ python3 credit.py
Number: 378282246310005
AMEX


Cash:

$ python3 cash.py
Change owed: 0.41
0.25 : 1
0.10 : 1
0.05 : 1
0.01 : 1
```
## Implementation tips
### Credit:
- Validate input str.isdigit() before processing; strip whitespace.
- Implement luhn_valid(number_str) -> bool and card_type(number_str) -> str for clean separation.
- Determine card type by len and prefixes:
    - AMEX: length 15, prefix 34 or 37
    - MASTERCARD: length 16, prefix 51–55 (and newer ranges if desired)
    - VISA: length 13 or 16, prefix 4

### Cash
- Use amount = float(input(...)) and cents = round(amount * 100).
- Iterate over coin values [25, 10, 5, 1], using integer division and remainder.
- Re-prompt while the provided amount is negative or input is invalid.

## Testing & edge cases
- Test credit.py with well-known valid/invalid card numbers and with non-digit input.
- Test cash.py with edge values: 0.00, small fractions (0.01), and larger amounts.
- Add small unit tests where convenient (e.g., for Luhn and coin-calculation functions).

Developed by Enzo C. Consulo as part of CS50 coursework.