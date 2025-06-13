#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a value into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Recursive search function
bool search(Node* root, int key) {
    if (root == nullptr) return false;

    if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    Node* root = nullptr;

    // Inserting some values into the BST
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        root = insert(root, values[i]);
    }

    // Display the BST in sorted order
    cout << "BST In-order Traversal (Ascending Order): ";
    inOrder(root);
    cout << endl;

    // Ask user to search a value
    int key;
    cout << "Enter a value to search in the BST: ";
    cin >> key;

    // Search using recursive function
    if (search(root, key)) {
        cout << "Value " << key << " found in the BST." << endl;
    }
    else {
        cout << "Value " << key << " NOT found in the BST." << endl;
    }

    return 0;
}
