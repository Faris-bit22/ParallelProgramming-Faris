cmake_minimum_required(VERSION 3.20)

project(ParallelProgramming C)

set(CMAKE_C_STANDARD 11)

add_executable(LAB01 LAB01/main.c
        LAB04/vector.h
        LAB04/vector.c
        LAB04/main.c)
add_executable(LAB02 LAB02/memory.c)
add_executable(LAB03 LAB03/leak.c)
add_executable(LAB04 LAB04/main.c LAB04/vector.c)