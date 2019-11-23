cmake_minimum_required(VERSION 3.0)
project(LinkedList)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -lstdc++ -lpthread")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
