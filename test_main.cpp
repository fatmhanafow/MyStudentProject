#include <gtest/gtest.h>
#include "main.cpp"  // Assuming the main BST implementation is in main.cpp

class BSTTest : public ::testing::Test {
protected:
    BST tree;  // Create a BST instance for each test
};

// Test for Insert
TEST_F(BSTTest, InsertWord) {
    tree.insert("apple");
    tree.insert("banana");

    // Check if the words are inserted correctly
    EXPECT_TRUE(tree.search("apple"));
    EXPECT_TRUE(tree.search("banana"));
    EXPECT_FALSE(tree.search("cherry"));  // Check for a word that is not in the tree
}

// Test for Delete
TEST_F(BSTTest, DeleteWord) {
    tree.insert("apple");
    tree.insert("banana");

    tree.deleteWord("apple");

    // Check if the word was deleted correctly
    EXPECT_FALSE(tree.search("apple"));
    EXPECT_TRUE(tree.search("banana"));
}

// Test for In-order Traversal
TEST_F(BSTTest, InOrderTraversal) {
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("cherry");

    testing::internal::CaptureStdout();  // Capture standard output
    tree.displayInorder();  // Display the tree in In-order traversal
    std::string output = testing::internal::GetCapturedStdout();  // Get the captured output

    // Check if all words appear in the output
    EXPECT_TRUE(output.find("apple") != std::string::npos);
    EXPECT_TRUE(output.find("banana") != std::string::npos);
    EXPECT_TRUE(output.find("cherry") != std::string::npos);
}

// Test for Pre-order Traversal
TEST_F(BSTTest, PreOrderTraversal) {
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("cherry");

    testing::internal::CaptureStdout();
    tree.displayPreorder();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if all words appear in the output
    EXPECT_TRUE(output.find("apple") != std::string::npos);
    EXPECT_TRUE(output.find("banana") != std::string::npos);
    EXPECT_TRUE(output.find("cherry") != std::string::npos);
}

// Test for Post-order Traversal
TEST_F(BSTTest, PostOrderTraversal) {
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("cherry");

    testing::internal::CaptureStdout();
    tree.displayPostorder();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if all words appear in the output
    EXPECT_TRUE(output.find("apple") != std::string::npos);
    EXPECT_TRUE(output.find("banana") != std::string::npos);
    EXPECT_TRUE(output.find("cherry") != std::string::npos);
}

