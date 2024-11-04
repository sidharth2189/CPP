cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 14)

project(cmake_example_project)

add_executable(example src/main.cpp src/sum.cpp)
