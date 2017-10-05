cmake_minimum_required(VERSION 3.7)
project(task2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c matrix.c matrix.h)
add_executable(task2 ${SOURCE_FILES})