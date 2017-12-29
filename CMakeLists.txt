cmake_minimum_required(VERSION 3.8)
project(stringset)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c stringset.h stringset.c node.c node.h)
add_executable(stringset ${SOURCE_FILES})