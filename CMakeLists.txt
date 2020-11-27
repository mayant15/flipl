cmake_minimum_required(VERSION 3.17)
project(flipl)

set(CMAKE_CXX_STANDARD 14)

include_directories(flipl/include)

add_executable(flipl
        examples/frames/newton_1.png
        examples/frames/newton_2.png
        examples/newton.fl
        flipl/include/application.h
        flipl/src/main.cpp
        .gitignore
        README.md)
