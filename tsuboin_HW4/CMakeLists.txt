cmake_minimum_required(VERSION 3.17)
project(HW4_428)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Werror -pedantic")
add_executable(BSTDriver BSTDriver.cpp BST.h)
#removed BST.cpp and added to bottom of .h file to make it work
