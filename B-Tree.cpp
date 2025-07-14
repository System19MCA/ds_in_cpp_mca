#include <iostream>
using namespace std;

// Minimum degree (defines the range for number of keys)
const int t = 3;

class BTreeNode {
    int* keys;
    int t;
    BTreeNode** C;
    int n;
    bool leaf;

public:
    BTreeNode(bool leaf);
    void traverse();
    BTreeNode* search(int k);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);

    friend class BTree;
};

class BTree {
    BTreeNode* root;

public:
    BTree() { root = nullptr; }
    void traverse() {
        if (root != nullptr) root->traverse();
    }
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }
    void insert(int k);
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(bool leaf1) {
    t = ::t;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode*[2 * t];
    n = 0;
}

// Traverse all nodes in a subtree rooted with this node
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

// Search key in subtree rooted with this node
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return C[i]->search(k);
}

// Insertion in non-full node
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// Splitting the child
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n = n + 1;
}

// Inserting a key
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(false);
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

// Main function
int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the B-tree is: ";
    t.traverse();

    int k = 6;
    (t.search(k) != nullptr) ? cout << "\nPresent: " << k : cout << "\nNot Present: " << k;

    k = 15;
    (t.search(k) != nullptr) ? cout << "\nPresent: " << k : cout << "\nNot Present: " << k;

    return 0;
}
