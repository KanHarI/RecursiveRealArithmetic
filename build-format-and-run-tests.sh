#!/bin/bash

if command -v clang-format > /dev/null 2>&1; then
	echo "Formatting source files with clang-format..."
	find . -path ./build -prune -o -type f \( -name "*.cpp" -or -name "*.h" -or -name "*.c" \) -exec clang-format -i {} \;
	echo "Source files formatted."
else
	echo "clang-format not found. Skipping formatting."
fi

echo "Building project..."
mkdir -p build
cd build

cmake -Wno-dev ..
make

echo "Running unit tests using ctest..."
ctest --output-on-failure
RESULT=$?
if [ $RESULT -ne 0 ]; then
	echo "ctest did not succeed. Running test executable directly..."
	cd tests
	./RecursiveRealArithmeticTests
else
	echo "All tests passed using ctest!"
fi
