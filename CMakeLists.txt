cmake_minimum_required(VERSION 3.10)
project(DictionaryProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add source files
set(SOURCES
    main.cpp
    bst.cpp  # Add other source files here
)

# Create the main executable
add_executable(DictionaryProject ${SOURCES})

# ----------- Google Test Setup --------------
# Find Google Test
find_package(GTest REQUIRED)

# Link Google Test libraries
target_link_libraries(DictionaryProject gtest gtest_main)

# Create the test executable
set(TEST_SOURCES
    test_bst.cpp  # Add your test source files here
)

add_executable(DictionaryProjectTests ${TEST_SOURCES})

# Link test executable with Google Test
target_link_libraries(DictionaryProjectTests gtest gtest_main)

# Add the test to the testing suite
add_test(NAME DictionaryTest COMMAND DictionaryProjectTests)
