# SPELLER C PROJECT

**Dictionary-based Spell Checker in C (CS50 Pset 5 — Speller)**

Following CS50 Speller specification:  
https://cs50.harvard.edu/x/2021/psets/5/speller/

## Features
- Loads an English dictionary into memory and checks words from a text for misspellings.  
- Implements a hash table of buckets with linked lists (separate chaining) to store dictionary words.  
- Provides the required API functions:
  - `bool load(const char *dictionary)` — loads dictionary into memory
  - `bool check(const char *word)` — returns whether `word` is in dictionary
  - `unsigned int size(void)` — returns number of words loaded
  - `bool unload(void)` — frees all memory used by the dictionary  
- Measures timing (load/check/unload) when run with provided test harnesses (optional).
- Optimized for speed and memory (custom hash function, bucket count tuning).

## Technologies
- C (ISO C11)  
- CS50 Library (`get_string`, `get_int`, optional test helpers)  
- GCC or Clang  
- Unix-like terminal (Linux, macOS, WSL)

## What I learned

* **Hash tables & hashing design:** implemented a custom hash function (multiplicative mix + modulo) and tuned the number of buckets (`N`) to trade memory for lookup speed; considered alternatives (djb2/FNV-1a) to reduce collisions.  
* **Case normalization:** normalized input to lowercase before lookup to make checks case-insensitive and consistent with the dictionary.  
* **Collision handling (separate chaining):** used linked lists (separate chaining) per bucket and implemented insertion at head for O(1) insert.  
* **Binary/text I/O:** reading words from a dictionary file using `fscanf`, and careful buffer sizing using `LENGTH + 1`.  
* **Memory management:** dynamically allocated nodes for each word and implemented a safe iterative `unload` to free all nodes without leaks.  
* **Performance considerations:** measured cost of `check` and `load`, discussed bucket sizing, and added optimizations (e.g., maintain a global word count to make `size()` O(1)).  
* **Edge-case handling & robustness:** handled non-alphabetic characters (apostrophes) intentionally in hashing/lookup, and validated allocations and file I/O (null checks).  
* **Testing & debugging tools:** used `valgrind` to verify zero leaks and used test inputs to exercise collision behavior and extreme cases.

## Project Structure
```
speller/
├─ speller.c # test harness / main (usually provided by CS50)
├─ dictionary.c # your dictionary implementation (load, check, size, unload)
├─ dictionary.h # prototypes & constants (e.g., N bucket size)
├─ Makefile # optional, or use clang commands below
└─ README.md # this file
```

## Compile & Run
```
# Using CS50's Makefile (if present)
make speller

# Or compile directly:
clang -o speller speller.c dictionary.c -lcs50 -std=c11

# Example run (with CS50-provided dictionaries/texts):
./speller dictionaries/large texts/hamlet.txt
```
## Typical output format (CS50 test harness prints timing and counts), example:
```
WORDS MISSPELLED: 123
WORDS IN DICTIONARY: 143091
WORDS IN TEXT: 31834
TIME IN load: 0.12
TIME IN check: 1.23
TIME IN size: 0.00
TIME IN unload: 0.02
TIME IN TOTAL: 1.37
```
## Notes & Tips
- Choose N (number of buckets) carefully — power-of-two or large prime numbers can impact distribution. Start with a few hundred thousand for large dictionary tests, then tune.
- Use a robust hash (e.g., djb2, FNV-1a, or a simple multiply–add) — test collision counts with your dictionaries.
- Store words in lowercase or compare case-insensitively to match CS50 behavior.
- load should allocate memory per word (e.g., malloc(sizeof(node)) plus strdup or malloc+strcpy).
- unload must free every node in every bucket; recursively or iteratively traverse linked lists and free nodes to avoid leaks. Use valgrind to confirm zero leaks.
- Convert words to char arrays and handle apostrophes (e.g., I'm) per spec.
- Consider limiting maximum word length per CS50 (LENGTH constant) and defensively check bounds when reading.

## Testing
- Test with the CS50-provided dictionaries/large, dictionaries/small, and multiple texts/ files to validate correctness and performance.
- Use valgrind --leak-check=full ./speller dictionaries/large texts/longtext.txt to ensure no leaks.
- Measure performance with time ./speller ... and iterate on the hash function / N to reduce collision rate and check time.

Developed by Enzo C. Consulo as part of Harvard’s CS50 curriculum (2025).
