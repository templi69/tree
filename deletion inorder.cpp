#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Inorder traversal (for sorted output)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find minimum in right subtree (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node in BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    // Go left if key is smaller
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // Go right if key is larger
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Found the node to delete
    else {
        // Case 1: No left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: No right child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right); // inorder successor
        root->data = temp->data;           // copy value
        root->right = deleteNode(root->right, temp->data); // delete successor
    }
    return root;
}

// Driver Code
int main() {
    Node* root = NULL;
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int v : values)
        root = insert(root, v);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with one child
    root = deleteNode(root, 30); // node 30 has one child (40)

    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << endl;

    return 0;
}
