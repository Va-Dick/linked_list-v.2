cmake_minimum_required(VERSION 3.0)

project(Test_runner)



enable_testing()


find_library(GTEST_LIB NAMES gtest)
find_library(GTEST_MAIN_LIB NAMES gtest_main)

add_executable(${PROJECT_NAME} tests.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIB} ${GTEST_MAIN_LIB})

add_test(${PROJECT_NAME} ${PROJECT_NAME})

