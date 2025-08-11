# Recover C Project

**JPEG Forensic Recovery in C (CS50 Pset 4)**

Following CS50 “Recover” specification:  
https://cs50.harvard.edu/x/psets/4/recover/

## Features

- Scans a forensic image (`card.raw`) for JPEG signatures  
- Recovers and writes each found JPEG as `###.jpg` (000.jpg, 001.jpg, …)  
- Handles contiguous data blocks (512 B) until next JPEG header

## Technologies

- C (ISO C11)  
- Standard `<stdio.h>` / `<stdlib.h>` for file I/O  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I Learned

- **Binary file I/O:** reading fixed-size blocks with `fread`/`fwrite`  
- **Byte-level pattern matching:** detecting JPEG header signatures (`0xff 0xd8 0xff 0xe?`)  
- **File management:** dynamically creating and closing output files  
- **Buffer handling:** managing memory and file pointers for streaming data  
- **Modular code:** clear separation of scanning and writing logic

## Structure
```
recover/
├─ recover.c # main driver: reads card.raw, detects headers, writes JPEGs
└─ README.md # this file
```

## Compile & Run

```
# Compile
clang -o recover recover.c

# Or with CS50’s Makefile:
make recover

# Execute
./recover card.raw
- Ensure card.raw is in the working directory.
- Program outputs recovered JPEGs as 000.jpg, 001.jpg, etc.
```
Notes
- Uses 512-byte buffer size per specification
- Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)
- All I/O via terminal; no GUI

— Enzo C. Consulo, CS50 2025
