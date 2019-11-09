cmake_minimum_required(VERSION 3.0)

project (LinkedList)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++1y -Wall")

file(GLOB CPP_SOURCES "*.cpp")

file(GLOB H_FILE "*.h")

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ${H_FILE})