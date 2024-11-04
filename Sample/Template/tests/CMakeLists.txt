# CMakeLists.txt for test directory
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# Minimum required version of CMake
cmake_minimum_required(VERSION 3.16.3)

# Project Name for tests
project(SumTests)

# Include the main CMakeLists.txt from root directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find the test framework
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#include_directories(${GTEST_INCLUDE_DIRS})

# Source files for tests
set(TEST_SOURCES test_sum.cpp)

# Create test executable
add_executable(runTests ${TEST_SOURCES})

# Link the testing framework
target_link_libraries(runTests gtest_main)

# Enable testing
enable_testing()

# Add a test
add_test(Name MyTests Command runTests)
