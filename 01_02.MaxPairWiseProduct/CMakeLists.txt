cmake_minimum_required(VERSION 3.5.1)
project(MaxPairwiseProduct)

set(CMAKE_CXX_STANDARD 11)

include_directories(../include)
include_directories(include)
add_subdirectory(test)

add_executable(MaxPairwiseProduct main.cpp)
