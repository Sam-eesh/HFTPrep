cmake_minimum_required(VERSION 3.20)
project(Week4_Move)

set(CMAKE_CXX_STANDARD 17)

add_executable(Week4_Move main.cpp )
target_compile_options(Week4_Move PRIVATE -Wall -Wextra -Werror -pedantic)