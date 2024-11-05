# CMakeLists.txt for test directory

include(CTest)

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

# Source files for tests
set(TEST_SOURCES test_sum.cpp)

# Create test executable
add_executable(runTests ${TEST_SOURCES})

# Enable coverage flags for GCC and Clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Enable coverage flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

  # Additional flags for debugging (optional)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
endif()

# Link the testing framework
target_link_libraries(runTests gtest_main)

# Enable testing
enable_testing()

# Add a test
add_test(Name runTests Command runTests)
