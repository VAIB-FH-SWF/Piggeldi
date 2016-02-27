cmake_minimum_required(VERSION 3.3)
project(Aufgabe1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PGMBild.cpp PGMBild.h Defines.h PGMBildRepo.cpp PGMBildRepo.h)
add_executable(Aufgabe1 ${SOURCE_FILES})