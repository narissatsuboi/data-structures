cmake_minimum_required(VERSION 3.17)
project(HW1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -W -Wall -pedantic")

add_executable(HW1 driver.cpp Calculator.cpp Calculator.h CalculatorIO.cpp CalculatorIO.h)