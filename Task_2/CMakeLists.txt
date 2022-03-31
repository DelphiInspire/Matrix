cmake_minimum_required(VERSION 3.21)
project(Task_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_2
        Exception.h
        main.cpp
        Matrix.cpp
        Matrix.h)
