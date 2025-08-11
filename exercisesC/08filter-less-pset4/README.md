# Filter-Less C Project

**BMP Image Filters in C (CS50 Pset 4)**

Following CS50 “Filter (Less Comfortable)” specification:  
https://cs50.harvard.edu/x/psets/4/filter/less/

## Features

- **Grayscale:** convert image to shades of gray  
- **Sepia:** apply sepia tone filter  
- **Reflect:** mirror image horizontally  
- **Blur:** apply box blur on each pixel  

## Technologies

- C (ISO C11)  
- CS50 Library (`get_int`, `get_string` if desired)  
- Standard `<stdio.h>` / `<stdlib.h>` for file I/O  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I Learned

- **BMP file I/O:** reading/writing `BITMAPFILEHEADER` & `BITMAPINFOHEADER`  
- **Pixel structs:** manipulating `RGBTRIPLE` arrays  
- **Edge-case handling:** skipping boundary pixels for blur  
- **Nested loops & arithmetic:** iterating image rows/columns, computing color transforms  
- **Modular code:** separating filter logic into `helpers.c` / `helpers.h`

## Structure
```
filter-less/
├─ filter.c # main driver: parses args, loops through pixels
├─ helpers.c # implementations: grayscale, sepia, reflect, blur
├─ helpers.h # function prototypes & RGBTRIPLE definition
└─ README.md # this file
```
## Compile & Run
```
# Compile with CS50’s Makefile
make filter

# Or with Clang/GCC directly:
clang -o filter filter.c helpers.c -lcs50

# Execute: apply each filter to an input BMP
./filter input.bmp output.bmp
1- Enter filter command with input and output BMP paths.
2- Choose filter by editing filter.c (e.g. call grayscale, sepia, reflect, or blur in main).
3- Inspect output.bmp in any image viewer.
```
## Notes
- Ensure input.bmp is 24-bit uncompressed BMP 4.0
- Linking CS50 library (-lcs50) isn’t strictly needed if not using get_ functions
- Tested on Ubuntu 22.04 & macOS Monterey (GCC 11, Clang 14)

— Enzo C. Consulo, CS50 2025
