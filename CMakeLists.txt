cmake_minimum_required(VERSION 3.16)
project(GOLFilter C)

set(CMAKE_C_STANDARD 99)

add_executable(GOLFilter main.c PPMReader.c)