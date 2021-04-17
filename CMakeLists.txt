cmake_minimum_required(VERSION 3.19)
project(List C)

set(CMAKE_C_STANDARD 11)

add_executable(List main.c List.h List.c ListIterator.h ListIterator.c)