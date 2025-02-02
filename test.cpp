#include <gtest/gtest.h>
#include "main.cpp"  // Adjust to include your project file

// Sample Test
TEST(BSTTest, InsertWord) {
    BST tree;
    tree.insert("apple");
    tree.insert("banana");

    EXPECT_TRUE(tree.search("apple"));
    EXPECT_TRUE(tree.search("banana"));
    EXPECT_FALSE(tree.search("cherry"));
}
