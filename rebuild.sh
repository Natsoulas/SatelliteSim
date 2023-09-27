#!/bin/bash

Remove the existing build directory if it exists
if [ -d "build" ]; then
    rm -r build
fi

# Create a new build directory
mkdir build

# Navigate to the build directory
cd build

# Generate build files using CMake
cmake ..

# Build the project (e.g., using Make)
make

# Run the executable (if desired)
# ./fast

# Navigate back to the project directory
cd ..