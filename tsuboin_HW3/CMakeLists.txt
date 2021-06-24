cmake_minimum_required(VERSION 3.17)
project(LectureCode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Werror -Wall -pedantic")

add_executable(StringDemo StringDemo.cpp ListInterface.h LinkedList.h String.cpp)
add_executable(ContainsDemo ContainsDemo.cpp ListInterface.h LinkedList.h)
add_executable(ListDriver ListDriver.cpp ListInterface.h LinkedList.h)
