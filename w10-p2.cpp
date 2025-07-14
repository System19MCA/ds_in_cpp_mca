#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BPlusTreeNode {
public:
    bool isLeaf;
    vector<int> keys;
    vector<BPlusTreeNode*> children;
    BPlusTreeNode* next; // Used for leaf nodes linkage

    BPlusTreeNode(bool leaf) : isLeaf(leaf), next(nullptr) {}

    // Utility to find the first index >= key
    int findKey(int key) {
        int idx = 0;
        while (idx < (int)keys.size() && keys[idx] < key) idx++;
        return idx;
    }
};

class BPlusTree {
private:
    BPlusTreeNode* root;
    int t; // minimum degree

    void insertInternal(int key, BPlusTreeNode* curr, BPlusTreeNode* child) {
        if (curr == nullptr) return;

        int i = curr->findKey(key);
        curr->keys.insert(curr->keys.begin() + i, key);
        curr->children.insert(curr->children.begin() + i + 1, child);

        if ((int)curr->keys.size() == 2 * t) {
            if (curr == root) {
                // Split root
                BPlusTreeNode* newRoot = new BPlusTreeNode(false);
                BPlusTreeNode* newNode = splitInternal(curr);
                newRoot->keys.push_back(curr->keys[t - 1]);
                newRoot->children.push_back(curr);
                newRoot->children.push_back(newNode);
                root = newRoot;
            } else {
                // This case will be handled in recursion (not implemented here for brevity)
            }
        }
    }

    BPlusTreeNode* splitInternal(BPlusTreeNode* node) {
        int mid = t;
        BPlusTreeNode* newNode = new BPlusTreeNode(false);

        newNode->keys.assign(node->keys.begin() + mid, node->keys.end());
        node->keys.erase(node->keys.begin() + mid - 1, node->keys.end());

        newNode->children.assign(node->children.begin() + mid, node->children.end());
        node->children.erase(node->children.begin() + mid, node->children.end());

        return newNode;
    }

    BPlusTreeNode* splitLeaf(BPlusTreeNode* leaf) {
        int mid = t;
        BPlusTreeNode* newLeaf = new BPlusTreeNode(true);

        newLeaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
        leaf->keys.erase(leaf->keys.begin() + mid, leaf->keys.end());

        // Link new leaf
        newLeaf->next = leaf->next;
        leaf->next = newLeaf;

        return newLeaf;
    }

    void insertNonFull(BPlusTreeNode* node, int key) {
        if (node->isLeaf) {
            int idx = node->findKey(key);
            node->keys.insert(node->keys.begin() + idx, key);

            if ((int)node->keys.size() == 2 * t) {
                if (node == root) {
                    // Split leaf root
                    BPlusTreeNode* newLeaf = splitLeaf(node);

                    BPlusTreeNode* newRoot = new BPlusTreeNode(false);
                    newRoot->keys.push_back(newLeaf->keys[0]);
                    newRoot->children.push_back(node);
                    newRoot->children.push_back(newLeaf);
                    root = newRoot;
                } else {
                    // For brevity, no recursive insertInternal call here
                }
            }
        } else {
            int idx = node->findKey(key);
            BPlusTreeNode* child = node->children[idx];

            if ((int)child->keys.size() == 2 * t - 1) {
                if (child->isLeaf) {
                    BPlusTreeNode* newLeaf = splitLeaf(child);
                    node->keys.insert(node->keys.begin() + idx, newLeaf->keys[0]);
                    node->children.insert(node->children.begin() + idx + 1, newLeaf);
                } else {
                    // For internal nodes splitting (not fully implemented here)
                }

                if (key >= node->keys[idx])
                    idx++;
            }
            insertNonFull(node->children[idx], key);
        }
    }

    bool searchKey(BPlusTreeNode* node, int key) {
        int i = node->findKey(key);

        if (node->isLeaf) {
            if (i < (int)node->keys.size() && node->keys[i] == key)
                return true;
            return false;
        } else {
            return searchKey(node->children[i], key);
        }
    }

    void printLeaves(BPlusTreeNode* node) {
        if (!node) return;
        while (!node->isLeaf)
            node = node->children[0];

        cout << "B+ Tree Leaves: ";
        while (node) {
            for (int k : node->keys)
                cout << k << " ";
            node = node->next;
        }
        cout << "\n";
    }

public:
    BPlusTree(int _t) : root(nullptr), t(_t) {}

    void insert(int key) {
        if (!root) {
            root = new BPlusTreeNode(true);
            root->keys.push_back(key);
            return;
        }
        insertNonFull(root, key);
    }

    bool search(int key) {
        if (!root) return false;
        return searchKey(root, key);
    }

    void displayLeaves() {
        printLeaves(root);
    }
};

int main() {
    int order = 3; // minimum degree (t)
    BPlusTree bpt(order);

    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    cout << "Inserting keys: ";
    for (int k : keys) cout << k << " ";
    cout << "\n";

    for (int k : keys) {
        bpt.insert(k);
    }

    bpt.displayLeaves();

    int searchKey = 12;
    cout << "Searching for key " << searchKey << ": "
         << (bpt.search(searchKey) ? "Found" : "Not Found") << "\n";

    searchKey = 15;
    cout << "Searching for key " << searchKey << ": "
         << (bpt.search(searchKey) ? "Found" : "Not Found") << "\n";

    return 0;
}
