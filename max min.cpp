#include <iostream>
using namespace std;

// BST Node structure
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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// In-order Traversal
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Recursive function to find minimum
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }

    if (root->left == nullptr)
        return root->data;
    return findMin(root->left);
}

// Recursive function to find maximum
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }

    if (root->right == nullptr)
        return root->data;
    return findMax(root->right);
}

int main() {
    Node* root = nullptr;

    // Sample BST insertions
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; ++i) {
        root = insert(root, values[i]);
    }

    // Show tree
    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    // Find and print min and max
    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}
