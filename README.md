# Data_Structure_Assignment1

C++ solutions and notes for **Data Structure Assignment 1**.

## Repository overview
This repository contains C++ source code for common data-structure exercises (e.g., arrays, linked lists, stacks, queues, trees, graphs), as assigned in *Assignment 1*.

> If you are looking for a specific question/solution, browse the source files in the repository root.

## Requirements
- A C++ compiler supporting **C++17** (or newer)
  - GCC / Clang / MSVC all work

## How to build & run
Because assignment repositories often contain multiple independent programs, compile the file you want to run.

### Linux / macOS (GCC/Clang)
```bash
# Replace FILE.cpp with the file you want to compile
g++ -std=c++17 -O2 -Wall -Wextra -pedantic FILE.cpp -o app
./app
```

### Windows (MSVC Developer Command Prompt)
```bat
REM Replace FILE.cpp with the file you want to compile
cl /std:c++17 /EHsc FILE.cpp
FILE.exe
```

## Project structure
Typical layouts you might see in this repo:
- `*.cpp` — solution source files
- `*.h` / `*.hpp` — helper headers (if any)

## Notes
- Each `.cpp` file is intended to be run independently unless stated otherwise in code comments.
- Input/output format is usually described at the top of each file.

## Contributing
If you want, open an issue or PR with:
- improvements to code clarity
- additional test cases
- fixes for edge cases

## License
No license file is currently included. If you want to allow reuse, consider adding a license (e.g., MIT).
