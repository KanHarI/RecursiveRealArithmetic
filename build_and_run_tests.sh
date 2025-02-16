#!/bin/bash

echo "Building project..."
mkdir -p build
cd build

cmake ..
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