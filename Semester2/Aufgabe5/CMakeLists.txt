cmake_minimum_required(VERSION 3.5)
project(Aufgabe5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Class.cpp Class.h)
add_executable(Aufgabe5 ${SOURCE_FILES})