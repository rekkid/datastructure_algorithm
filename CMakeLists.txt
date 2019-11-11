cmake_minimum_required(VERSION 3.6)
project(hupfen)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES datastructure/array/array.cpp)
add_executable(array ${SOURCE_FILES})
