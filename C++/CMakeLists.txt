cmake_minimum_required(VERSION 3.5.1)
project(DataStructuresAndAlgorithms)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g")

enable_testing()

include_directories(include)

add_subdirectory(googletest)
add_subdirectory(01.AlgorithmicToolbox)
add_subdirectory(02.DataStructures)
