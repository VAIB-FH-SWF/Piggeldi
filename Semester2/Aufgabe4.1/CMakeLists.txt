cmake_minimum_required(VERSION 3.5)
project(Aufgabe4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Mitarbeiter.cpp Mitarbeiter.h Person.h)
add_executable(Aufgabe4.1 ${SOURCE_FILES})