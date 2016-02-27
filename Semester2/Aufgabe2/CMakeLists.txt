cmake_minimum_required(VERSION 3.3)
project(Aufgabe2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Cell.cpp Cell.h Board.cpp Board.h God.cpp God.h Lifecycle.cpp Lifecycle.h)
add_executable(Aufgabe2 ${SOURCE_FILES})