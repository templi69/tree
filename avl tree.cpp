#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = NULL;
        height = 1; // new node is always added at height 1
    }
};

// Get height of a node
int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        return node->height;
    }
}

// Get balance factor of a node
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return leftHeight - rightHeight;
    }
}

// Get maximum of two numbers
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

// Perform a right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    // Return new root
    return x;
}

// Perform a left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    // Return new root
    return y;
}

// Insert into AVL tree
Node* insert(Node* root, int value) {
    // Step 1: Normal BST insert
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        // Duplicate values are not allowed
        return root;
    }

    // Step 2: Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Step 3: Get balance factor to check if unbalanced
    int balance = getBalance(root);

    // Step 4: Perform rotations if needed

    // Left Left (LL) Case
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    // Right Right (RR) Case
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    // Left Right (LR) Case
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left (RL) Case
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // return unchanged if no rotation was needed
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int values[] = { 10, 20, 30, 40, 50, 25 };

    for (int i = 0; i < 6; i++) {
        root = insert(root, values[i]);
    }

    cout << "Inorder traversal of AVL Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
