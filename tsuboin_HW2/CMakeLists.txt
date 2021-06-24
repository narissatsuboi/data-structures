cmake_minimum_required(VERSION 3.17)
project(HW2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -pedantic")

add_executable(HW2P1 palindrome.cpp )
add_executable(HW2P2 fib.cpp)
add_executable(HW2P3 reversevec.cpp)
add_executable(HW2P4 coinchange.cpp)
