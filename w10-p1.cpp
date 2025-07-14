#include <iostream>
using namespace std;

class BTreeNode {
    int* keys;        // Array of keys
    int t;            // Minimum degree
    BTreeNode** C;    // Child pointers
    int n;            // Current number of keys
    bool leaf;        // Is true when node is leaf

public:
    BTreeNode(int _t, bool _leaf);

    void traverse();             // In-order traversal
    BTreeNode* search(int k);    // Search key

    void insertNonFull(int k);   // Insert into non-full node
    void splitChild(int i, BTreeNode* y); // Split child

    friend class BTree;
};

class BTree {
    BTreeNode* root;
    int t;

public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

// Constructor
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new int[2*t - 1];
    C = new BTreeNode *[2*t];
    n = 0;
}

// Traverse
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (!leaf)
        C[i]->traverse();
}

// Search
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (i < n && keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return C[i]->search(k);
}

// Insert in non-full node
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        // Shift keys to insert
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }

        keys[i+1] = k;
        n++;
    } else {
        // Find child
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i+1]->n == 2*t - 1) {
            splitChild(i+1, C[i+1]);

            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

// Split child
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    y->n = t - 1;

    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    C[i+1] = z;

    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[t-1];
    n++;
}

// Insert key into tree
void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2*t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// Main driver
int main() {
    int t;
    cout << "Enter minimum degree (t) of B-Tree: ";
    cin >> t;
    BTree tree(t);

    int choice, value;

    do {
        cout << "\nB-Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Traverse (Inorder)\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "B-tree traversal:";
            tree.traverse();
            cout << endl;
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value))
                cout << value << " found in B-tree.\n";
            else
                cout << value << " not found.\n";
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
