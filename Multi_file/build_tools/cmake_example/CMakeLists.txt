cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project(cmake_example_project)

add_executable(example  src/main.cpp src/increment_and_sum.cpp src/vect_add_one.cpp)