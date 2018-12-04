cmake_minimum_required(VERSION 3.12)
project(Calculator C)

set(CMAKE_C_STANDARD 99)

add_executable(Calculator main.c list.h list.c evaluator.c evaluator.h map.c map.h variable.c variable.h function.c function.h util.c util.h command.c command.h)