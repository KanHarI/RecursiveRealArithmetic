# RecursiveRealArithmetic

A C++ library for recursive real arithmetic computations.

## Overview

This library provides basic functionality for recursive real arithmetic operations. Currently, it includes a sample function `compute` that returns twice the input value.

## Build Instructions

### Prerequisites

- CMake (version 3.10 or higher)
- A C++ compiler that supports C++14 (e.g., AppleClang)
- Git (if you need to fetch external dependencies)

### Steps to Build

1. Create a build directory and navigate into it:
   ```sh
   mkdir build && cd build
   ```
2. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
3. Build the project:
   ```sh
   make
   ```

## Running Unit Tests

The project uses GoogleTest for unit testing. After building the project, you can run the tests in one of the following ways:

### Using CTest

From the build directory, execute:
   ```sh
   ctest --output-on-failure
   ```

### Running the Test Executable Directly

From the build directory, run:
   ```sh
   ./tests/RecursiveRealArithmeticTests
   ```

## Project Structure

- `src/`: Contains the source code for the RecursiveRealArithmetic library.
- `include/`: Contains the header files for the library.
- `tests/`: Contains unit tests and CMake configuration for tests.
- `CMakeLists.txt`: The main CMake file for the project.

## Dependencies

The project fetches GoogleTest automatically via CMake's FetchContent module. Ensure you have an internet connection when building for the first time.

## License

Add your license information here.
