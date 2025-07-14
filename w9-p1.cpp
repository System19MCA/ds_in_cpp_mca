#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to find the minimum value node in a subtree
Node* findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal (for printing the tree)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of nodes to insert: ";
    cin >> n;
    cout << "Enter values to insert into BST: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    cout << "Enter value to delete from BST: ";
    int delValue;
    cin >> delValue;

    root = deleteNode(root, delValue);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
