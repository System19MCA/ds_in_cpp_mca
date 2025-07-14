#include <iostream>
using namespace std;

const int M = 4; // Order of the M-way search tree

struct MWayNode {
    int keys[M - 1];               // Max M-1 keys
    MWayNode* children[M];         // Max M children
    int numKeys;

    MWayNode() {
        numKeys = 0;
        for (int i = 0; i < M - 1; i++) keys[i] = 0;
        for (int i = 0; i < M; i++) children[i] = nullptr;
    }
};

// Utility to insert a key in a node (no overflow handling here)
void insertNonFull(MWayNode* node, int key) {
    int i = node->numKeys - 1;

    // If it's a leaf node
    if (node->children[0] == nullptr) {
        // Move keys to make space
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        // Find child to recurse into
        while (i >= 0 && key < node->keys[i]) i--;
        i++;

        if (node->children[i] == nullptr)
            node->children[i] = new MWayNode();

        insertNonFull(node->children[i], key);
    }
}

// Inorder traversal of M-way tree
void inorder(MWayNode* node) {
    if (node == nullptr) return;

    for (int i = 0; i < node->numKeys; i++) {
        inorder(node->children[i]);
        cout << node->keys[i] << " ";
    }
    inorder(node->children[node->numKeys]);
}

// Search for a key in M-way search tree
bool search(MWayNode* node, int key) {
    if (node == nullptr) return false;

    int i = 0;
    while (i < node->numKeys && key > node->keys[i])
        i++;

    if (i < node->numKeys && key == node->keys[i])
        return true;

    return search(node->children[i], key);
}

int main() {
    MWayNode* root = new MWayNode();
    int choice, value;

    do {
        cout << "\nM-Way Search Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNonFull(root, value);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << value << " found in the tree.\n";
            else
                cout << value << " not found.\n";
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
