# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Source Files
SRC = main.cpp
TEST_SRC = test.cpp
EXEC = bstDict
TEST_EXEC = test_bst

# Default target: Compile the main program
all: $(EXEC)

# Compile the main BST dictionary program
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

# Compile and run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Compile test file with Google Test
$(TEST_EXEC): $(TEST_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(SRC) -o $(TEST_EXEC) $(GTEST_LIBS)

# Clean up generated files
clean:
	rm -f $(EXEC) $(TEST_EXEC)

