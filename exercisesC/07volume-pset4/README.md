# VOLUME C PROJECT

**WAV Audio Volume Modifier in C (CS50 Lab 4)**

Following CS50 Lab 4 specification (Volume):
[https://cs50.harvard.edu/x/2021/labs/4/](https://cs50.harvard.edu/x/2021/labs/4/)

## Features

* Reads a 16-bit PCM WAV file and scales its samples by a user-provided factor (e.g., 0.5 to halve volume, 2.0 to double).
* Preserves WAV headers while modifying sample data.
* Clips samples to the 16-bit signed range to avoid overflow.

## Technologies

* C (ISO C11)
* Standard `<stdio.h>` / `<stdint.h>` / `<stdlib.h>` for file and binary I/O
* GCC or Clang
* Unix-like terminal (Linux, macOS, WSL)

## What I Learned

* **Binary file I/O:** reading/writing WAV headers and sample blocks with `fread`/`fwrite`.
* **Endianness & sample formats:** handling 16-bit signed samples (`int16_t`).
* **Scaling & clipping:** multiplying samples by a float factor and clamping results to \[-32768, 32767].
* **Command-line arguments & validation:** parsing factor and input/output filenames and validating inputs.
* **Buffering:** processing large files in streams (sample-by-sample or in chunks) to keep memory usage low.

## Structure

```
volume/
├─ volume.c        # main program: parses args, reads headers, scales samples
└─ README.md       # this file
```

## Compile & Run

```
# Compile
clang -o volume volume.c
# or
make volume

# Execute
./volume factor input.wav output.wav
# Example: halve volume
./volume 0.5 input.wav output.wav
# Example: double volume
./volume 2.0 input.wav output.wav
```

* `factor` should be a positive floating-point number.
* `input.wav` must be a 16-bit PCM WAV file.

## Notes

* The program copies the WAV headers unchanged and only modifies sample data. Ensure the input format matches the spec (usually 44-byte header for standard WAV files).
* Clipping is applied to avoid integer overflow when scaling.
* Tested on Ubuntu 22.04 & macOS (GCC 11, Clang 14).

— Enzo C. Consulo, CS50 2025
