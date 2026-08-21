# c-string-transformation-pipeline

A modular C library for chaining string transformations (reverse, case conversion, shuffle) using function pointers and a custom dynamic storage structure.

## Overview

This program lets a user select a sequence of string transformations: reverse, uppercase, lowercase, toggle case, shuffle, or no-op, and applies them one after another to an input string. Each step's output feeds into the next step's input, and the result after every step is printed.

## Architecture

The project is split into three independent modules to separate concerns:

- **`library.c` / `library.h`** — the transformation functions themselves (pure string-in, string-out logic)
- **`storage.c` / `storage.h`** — a custom dynamic array data structure that stores function pointers and grows at runtime using `malloc`/`realloc`
- **`main.c`** — handles user input/output and orchestrates the pipeline

This separation means new transformation functions can be added to the library without touching the storage or control-flow code.

## Building

```bash
gcc -o pipeline main.c storage.c library.c
```

## Usage

```bash
./pipeline
Number of string transformation steps that you want to apply: 
2
Assigning function for step #1 out of 2: 
Available functions:
1. Reverse String
2. Uppercase String
3. Lowercase String
4. Toggle Case String
5. Shuffle String
6. Keep String the Same
Select function number (1-6): 1
Function 'Reverse String' assigned to step #1.
...
Enter input string: hello world
Result after step 1: dlrow olleh
Result after step 2: DLROW OLLEH
```

## Key Concepts Demonstrated

- Function pointers as first-class values (stored in an array and invoked dynamically)
- Manual dynamic memory management (`malloc`/`realloc`/`free`) with a growable array
- Modular program design with clear separation between data, logic, and control flow
