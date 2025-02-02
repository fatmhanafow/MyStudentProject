#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;

// Node structure for the tree
struct Node {
    string englishWord; 
    Node* left;
    Node* right;

    Node(string eng) : englishWord(eng), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) class
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    void insertNode(Node*& node, const string& english) {
        if (node == nullptr)
            node = new Node(english);
        else if (english < node->englishWord)
            insertNode(node->left, english);
        else if (english > node->englishWord)
            insertNode(node->right, english);
    }

    // Helper function to search for a word
    bool searchNode(Node* node, const string& english) {
        if (node == nullptr) return false;
        if (english == node->englishWord) {
            cout << "Word found: " << node->englishWord << endl;
            return true;
        }
        if (english < node->englishWord) return searchNode(node->left, english);
        return searchNode(node->right, english);
    }

    // Helper function to traverse the tree in-order
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->englishWord << endl;
            inorderTraversal(node->right);
        }
    }

    // Helper function to traverse the tree pre-order
    void preorderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->englishWord << endl;
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function to traverse the tree post-order
    void postorderTraversal(Node* node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->englishWord << endl;
        }
    }

    // Helper function to delete a word from the tree
    Node* deleteNode(Node* node, const string& english) {
        if (node == nullptr) return node;
        if (english < node->englishWord)
            node->left = deleteNode(node->left, english);
        else if (english > node->englishWord)
            node->right = deleteNode(node->right, english);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->englishWord = temp->englishWord;
            node->right = deleteNode(node->right, temp->englishWord);
        }
        return node;
    }

    // Helper function to find the minimum value node in the tree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Helper function to save the tree to a CSV file
    void saveToCSVRec(Node* node, ofstream& outfile) {
        if (node != nullptr) {
            saveToCSVRec(node->left, outfile);
            outfile << "\"" << node->englishWord << "\"" << endl;
            saveToCSVRec(node->right, outfile);
        }
    }

    // Destructor to deallocate memory for the tree
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    // Destructor to clean up the tree
    ~BST() {
        deleteTree(root);
    }

    // Function to insert a word into the tree
    void insert(const string& english) {
        insertNode(root, english);
    }

    // Function to search for a word in the tree
    bool search(const string& english) {
        return searchNode(root, english);
    }

    // Function to delete a word from the tree
    void deleteWord(const string& english) {
        root = deleteNode(root, english);
    }

    // Function to display the tree in in-order traversal
    void displayInorder() {
        inorderTraversal(root);
    }

    // Function to display the tree in pre-order traversal
    void displayPreorder() {
        preorderTraversal(root);
    }

    // Function to display the tree in post-order traversal
    void displayPostorder() {
        postorderTraversal(root);
    }

    // Function to save the tree to a CSV file
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "English Word\n";  // Header for CSV
            saveToCSVRec(root, outFile);
            outFile.close();
            cout << "Tree saved to file." << endl;
        } else {
            cout << "Error opening the file." << endl;
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "1. Display tree\n";
    cout << "2. Search for a word\n";
    cout << "3. Add a word\n";
    cout << "4. Delete a word\n";
    cout << "5. Save tree to CSV file\n";
    cout << "6. Pre-order traversal\n";
    cout << "7. In-order traversal\n";
    cout << "8. Post-order traversal\n";
    cout << "9. Exit\n";
    cout << "Choose an option: ";
}

// Main function to interact with the user
int main() {
    BST tree;
    int choice;
    string english;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                tree.displayInorder();  // Display the tree in In-order
                break;
            case 2:
                cout << "Enter the English word: ";
                cin >> english;
                if (!tree.search(english))
                    cout << "Word not found." << endl;
                break;
            case 3:
                cout << "Enter the English word: ";
                cin >> english;
                tree.insert(english);
                break;
            case 4:
                cout << "Enter the English word to delete: ";
                cin >> english;
                tree.deleteWord(english);
                break;
            case 5:
                tree.saveToFile("dictionary.csv");
                break;
            case 6:
                tree.displayPreorder();  // Display the tree in Pre-order
                break;
            case 7:
                tree.displayInorder();  // Display the tree in In-order
                break;
            case 8:
                tree.displayPostorder();  // Display the tree in Post-order
                break;
            case 9:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 9);

    return 0;
}
