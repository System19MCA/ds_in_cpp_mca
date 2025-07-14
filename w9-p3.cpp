#include <iostream>
using namespace std;

// Node structure for a Threaded Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread; // true if right pointer is a thread

    Node(int val) {
        data = val;
        left = right = nullptr;
        rightThread = true;
    }
};

// Insert a node into a threaded binary tree
Node* insert(Node* root, int key) {
    Node* ptr = root;
    Node* parent = nullptr;

    // Find the location to insert the new node
    while (ptr != nullptr) {
        if (key == ptr->data) {
            cout << "Duplicate keys not allowed\n";
            return root;
        }
        parent = ptr;
        if (key < ptr->data)
            ptr = ptr->left;
        else {
            if (!ptr->rightThread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* newNode = new Node(key);

    if (parent == nullptr) {
        root = newNode;
        newNode->right = nullptr;
    } else if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;
    } else {
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightThread = false;
    }

    return root;
}

// Inorder traversal of a threaded binary tree
void inorder(Node* root) {
    Node* curr = root;

    // Go to the leftmost node
    while (curr && curr->left != nullptr)
        curr = curr->left;

    while (curr != nullptr) {
        cout << curr->data << " ";

        // If this node is threaded, go to inorder successor
        if (curr->rightThread)
            curr = curr->right;
        else {
            // Else go to leftmost node in right subtree
            curr = curr->right;
            while (curr && curr->left != nullptr)
                curr = curr->left;
        }
    }
}

// Main driver function
int main() {
    Node* root = nullptr;
    int choice, val;

    do {
        cout << "\nThreaded Binary Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
