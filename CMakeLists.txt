cmake_minimum_required(VERSION 3.16.3)
project(Darwin_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Darwin_Project main.cpp population.cpp population.h individual.cpp individual.h)
