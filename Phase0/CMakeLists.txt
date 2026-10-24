
cmake_minimum_required(VERSION 4.2)
project(Phase0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(Phase0 main.cpp
        math_engine.cpp
)