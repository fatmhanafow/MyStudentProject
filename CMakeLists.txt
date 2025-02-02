# Assuming your project source files are in the same directory as CMakeLists.txt
add_executable(MyStudentProject main.cpp)

# Add the GoogleTest library directory
link_directories(C:/Users/Webhouse/googletest/build/lib/Debug)

# Link gtest, gmock, and their main libraries to your project
target_link_libraries(MyStudentProject gtest gtest_main gmock gmock_main)
