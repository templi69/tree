#include <iostream>
using namespace std;

const int MAX_CHILDREN = 10; // Set a maximum number of children per node

// Node structure
struct Node {
    int data;
    Node* children[MAX_CHILDREN]; // array of child pointers
    int childCount; // current number of children

    Node(int val) {
        data = val;
        childCount = 0;
        for (int i = 0; i < MAX_CHILDREN; ++i)
            children[i] = nullptr;
    }
};

// Tree class
class Tree {
private:
    Node* root;

public:
    Tree(int rootData) {
        root = new Node(rootData);
    }

    Node* getRoot() {
        return root;
    }

    void addChild(Node* parent, int childData) {
        if (!parent || parent->childCount >= MAX_CHILDREN) {
            cout << "Cannot add child (limit reached or parent null)." << endl;
            return;
        }

        parent->children[parent->childCount++] = new Node(childData);
    }
    

    void display(Node* node, int depth = 0) {
        if (!node) return;

        for (int i = 0; i < depth; ++i) cout << "--";
        cout << node->data << endl;

        for (int i = 0; i < node->childCount; ++i) {
            display(node->children[i], depth + 1);
        }
    }
};

int main() {
    Tree myTree(1); // Root node with data 1

    Node* root = myTree.getRoot();
    myTree.addChild(root, 2);
    myTree.addChild(root, 3);
    myTree.addChild(root, 4);

    Node* node2 = root->children[0]; // Node with data 2
    myTree.addChild(node2, 5);
    myTree.addChild(node2, 6);

    Node* node3 = root->children[1]; // Node with data 3
    myTree.addChild(node3, 7);

    cout << "Tree Structure:\n";
    myTree.display(root);

    return 0;
}
