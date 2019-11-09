cmake_minimum_required(VERSION 3.0)
project(ExampleProject)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1y -Wall")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)