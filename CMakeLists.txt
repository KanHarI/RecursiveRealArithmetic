cmake_minimum_required(VERSION 3.10)
project(RecursiveRealArithmetic VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add library target
add_library(${PROJECT_NAME} STATIC
    src/RecursiveRealArithmetic.cpp
    src/utils.cpp
)

# Optionally set target properties
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Optionally turn on position independent code (important for shared libs on some platforms)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable testing
enable_testing()
include(CTest)

# Add GoogleTest as an external dependency or find it on your system.
# If you do not have it installed and want CMake to fetch it automatically, you can do:
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add subdirectories
# add_subdirectory(src)  (disabled because src contains no CMakeLists.txt)
add_subdirectory(tests)
