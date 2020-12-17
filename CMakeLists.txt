cmake_minimum_required(VERSION 3.17)
project(get_next_line_5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(get_next_line_5
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c)
