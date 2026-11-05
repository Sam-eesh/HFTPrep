cmake_minimum_required(VERSION 3.20)
project(HFTPrep_Workspace)
set(CMAKE_CXX_STANDARD 20)

# This tells the build system to compile your separate phase folders
add_subdirectory(Phase0)
add_subdirectory(Week2_Memory)
add_subdirectory(Week3_OOP)