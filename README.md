# Dictionary Project (BST Implementation)

This is a simple dictionary application using a Binary Search Tree (BST) in C++. It stores English words and allows you to perform basic operations like inserting words, searching for words, deleting words, and displaying them in various traversal orders (In-order, Pre-order, Post-order). The tree structure can be saved to a CSV file for future use.

## Features

- **Insert a word**: Add new English words to the tree.
- **Search for a word**: Find out if a specific word exists in the dictionary.
- **Delete a word**: Remove a word from the dictionary.
- **Traversal**: Display the dictionary in In-order, Pre-order, and Post-order traversals.
- **Save to CSV**: Save the dictionary to a CSV file for backup or sharing.

## Prerequisites

Before running this program, make sure you have a C++ compiler installed.  

## Compilation and Execution

To compile and run the project, follow these steps:

### 1. Clone the repository:
```bash
git clone https://github.com/fatmhanafow/MyStudentProject.git
cd MyStudentProject
```

### 2. Compile and run the program:

If you are using a Linux/Mac system, open a terminal and use the following commands to compile and run the program:

```bash
g++ main.cpp -o bstDict
./bstDict
```
### 3. Saving Data to CSV

The program can save the tree data to a CSV file for backup or sharing purposes. The file will be named `dictionary.csv`, and each English word will be stored on a new line. The CSV file will only contain the English words, without their meanings, for simplicity.

After performing any operation in the program, you can save the data by selecting the `Save to CSV` option from the menu.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository, make changes, and create a pull request. You can also open an issue if you find any bugs or have suggestions for improvements.

