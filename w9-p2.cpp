#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

// Function to get height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to get balance factor of a node
int getBalance(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to update height of a node
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insertion in AVL Tree
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed

    updateHeight(root);

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a node from AVL Tree
Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    updateHeight(root);
    int balance = getBalance(root);

    // Rebalance
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Main function to demonstrate AVL operations
int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\nAVL Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Inorder traversal: ";
            inOrder(root);
            cout << endl;
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
