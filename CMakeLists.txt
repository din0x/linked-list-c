cmake_minimum_required(VERSION 3.27)
project(linked_list C)

set(CMAKE_C_STANDARD 23)

add_executable(linked_list src/main.c
        src/linked.h)
