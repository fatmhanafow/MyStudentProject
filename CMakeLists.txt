cmake_minimum_required(VERSION 3.10)

# Project Name
project(MyStudentProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# GoogleTest setup
add_subdirectory(C:/Users/Webhouse/googletest)  
include_directories(C:/Users/Webhouse/googletest/googletest/include)

# Your main project source files
add_executable(MyStudentProject main.cpp)

# GoogleTest Linking
target_link_libraries(MyStudentProject gtest gtest_main)

# Testing
enable_testing()
add_test(NAME MyTest COMMAND MyStudentProject)

