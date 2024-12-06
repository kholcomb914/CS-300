cmake_minimum_required(VERSION 3.20)

set(this Hamming)
project(${this} CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main main.cpp hamming.cpp)

enable_testing()
add_subdirectory(googletest)

add_library(${this} hamming.hpp hamming.cpp)
add_subdirectory(tests)