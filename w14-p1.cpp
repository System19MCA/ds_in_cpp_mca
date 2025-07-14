#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = EMPTY;
    }

    void insert(int key) {
        int index = hash(key);
        int startIndex = index;
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Hash table is full! Cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    bool search(int key) {
        int index = hash(key);
        int startIndex = index;
        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex)
                break;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        int startIndex = index;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Deleted key " << key << " from index " << index << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex)
                break;
        }
        cout << "Key " << key << " not found!\n";
    }

    void display() {
        cout << "\nHash Table contents:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            if (table[i] == EMPTY)
                cout << "EMPTY";
            else if (table[i] == DELETED)
                cout << "DELETED";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key))
                cout << "Key " << key << " found.\n";
            else
                cout << "Key " << key << " not found.\n";
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
            break;
        case 4:
            ht.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
