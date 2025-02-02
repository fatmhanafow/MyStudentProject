cmake_minimum_required(VERSION 3.10)

project(MyStudentProject)

set(CMAKE_CXX_STANDARD 11)

# Add googletest subdirectory
add_subdirectory(C:/Users/Webhouse/googletest)

# Your executable
add_executable(MyStudentProject main.cpp)

# Link GoogleTest
target_link_libraries(MyStudentProject gtest gtest_main)

enable_testing()
add_test(NAME MyTest COMMAND MyStudentProject)
