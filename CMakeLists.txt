cmake_minimum_required(VERSION 3.21)
project(mem_alloc C)

set(CMAKE_C_STANDARD 11)

add_executable(mem_alloc main.c mem.c mem.h mem_debug.c mem_internals.h util.c util.h tests.c tests.h)
