// Write a program to delete a node in a binary search tree?

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST{
    Node* root;
    void _inorder(Node* node){
        if(node != nullptr){
            _inorder(node->left);
            cout<<node->data<<", ";
            _inorder(node->right);
        }
    }
public:
    BST(){
        this->root = nullptr;
    }

    void insert(int data){
        Node* newNode = new Node(data);
        Node* curr = root;
        if(this->root == nullptr) this->root = newNode;
        else{
            while(curr != nullptr){
                if(data < curr->data){
                    if(curr->left == nullptr){
                        curr->left = newNode;
                        return;
                    }else curr = curr->left;
                }else if(data > curr->data){
                    if(curr->right == nullptr){
                        curr->right = newNode;
                        return;
                    }else curr = curr->right;
                }else return;
            }
        }
    }

    bool search(int data){
        Node* curr = this->root;
        while(curr != nullptr){
            if(curr->data == data) return true;
            else if(data < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }

    Node* searchNode(int data){
        Node* curr = this->root;
        while(curr != nullptr){
            if(curr->data == data) return curr;
            else if(data < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return nullptr;
    }
   
    Node* getParent(Node* node){
        Node* curr = this->root;
        Node* prev = nullptr;

        while(curr != nullptr){
            if(node == curr) return prev;
            else if(node->data < curr->data) {
                prev = curr;
                curr = curr->left;
            }else{
                prev = curr;
                curr = curr->right;
            }
        }
        return nullptr;
    }
    
    int getChildrenLength(Node* node){
        int count = 0;
        if(node == nullptr) return count;
        if(node->left != nullptr) count++;
        if(node->right != nullptr) count++;
        return count;
    }

    Node* getMinNode(Node* node){
        Node* curr = node;
        while(curr->left != nullptr) curr = curr->left;
        return curr;
    }
    void remove(int data){
        Node* node = searchNode(data);
        Node* parent = getParent(node);
        int numberOfChildren = getChildrenLength(node);

        if(numberOfChildren == 0){
            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }else if(numberOfChildren == 1){
            if(parent->left == node){
                if(node->left != nullptr) parent->left = node->left;
                else parent->left = node->right;
            } else{
                if(node->left != nullptr) parent->right = node->left;
                else parent->right = node->right;
            }
        }else {
            // 2 children
            Node* minNode = getMinNode(node->right);
            Node* minParent = getParent(minNode);
            int minNodeChildrensCount = getChildrenLength(minNode);
            // This can have 0 or 1 child
            if( minNodeChildrensCount == 0){
                minParent->right = nullptr;
            }else{
                minParent->right = minNode->right;
            }
            
            minNode->right = node->right;
            minNode->left = node->left;

            if(parent->left == node) parent->left = minNode;
            else parent->right = minNode;

        }
    }

    void inorder(){
        cout<<"Inorder: ";
        _inorder(this->root);
        cout<<endl;
    }

    
    
};

int main(){
    BST b;
     //         50
    //     25          100
    // 1       29    80      120
    //                   110
    //                       115
    b.insert(50);
    b.insert(25);
    b.insert(100);
    b.insert(1);
    b.insert(29);
    b.insert(80);
    b.insert(120);
    b.insert(110);
    b.insert(115);

    cout<<"search 100: "<<b.search(100)<<endl;
    b.remove(100);
    cout<<"search 100: "<<b.search(100)<<endl;
    
    // DELETE created a loop :-(

    return 0;
}