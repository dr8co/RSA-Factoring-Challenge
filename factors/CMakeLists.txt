cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD  17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Ofast -lgmpxx -lgmp")

include_directories(..)

add_executable(factors main.cpp ../read_nums.cpp ../BigInt.cpp ../BigInt.h)
