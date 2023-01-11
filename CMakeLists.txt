cmake_minimum_required(VERSION 3.24)

project(RSA CXX)

set(CMAKE_CXX_STANDARD  17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Ofast")

include_directories(.)

add_executable(rsa
        main.cpp read_nums.cpp)