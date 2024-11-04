# Minimum required version of CMake
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 14)

# Project Name
project(cmake_sample_project)

# Include directories
include_directories(include)

# Add source files
add_library(sum src/sum.cpp)

# Enable Testing
enable_testing()

# Add sub directory for tests
add_subdirectory(tests)
