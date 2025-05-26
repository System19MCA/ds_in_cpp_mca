#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node *next;
    Node *prev;

    Node(T val)
    {
        this->val = val;
        next = prev = nullptr;
    }
};

template <class T>
class DoublyLinkedList
{
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insert(T val)
    {
        Node<T> *node = new Node(val);
        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
        tail = node;
    }

    void insertAt(int pos, T val){
        Node<T> *node = new Node(val);
        if(pos ==0 && head = nullptr){
            head= node;
            return;
        }
        if(pos == 0 ){
            node->next= head;
            head->prev= node;
            head= node;
            return;
        }

        Node<T> *currNode = head;
        Node<T> *prevNode = nullptr;
        int count=0;

        while (count != pos && currNode != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
            count++;

        }
        if(count==pos){
            prevNode->next = node;
            node->prev= prevNode;
            if(currNode->next == nullptr){
         // pending
            }
            node->next = currNode;
            currNode->prev= node;


        }else{
            cout << "invalid positoin ";// or call insert at end
            
        }
        



    }

    void deleteNode(T val)
    {
        Node<T> *curr = head;

        if (curr == nullptr)
            return;

        // head deleted
        if (curr->val == val)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr; // empty list
            delete curr;
            return;
        }

        while (curr != nullptr && curr->val != val)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Node not present" << endl;
            return;
        }

        Node<T> *prevNode = curr->prev;
        Node<T> *nextNode = curr->next;

        if (nextNode != nullptr)
        {
            nextNode->prev = prevNode;
        }
        else
        {
            // deleting  tail node
            tail = prevNode;
        }

        if (prevNode != nullptr)
        {
            prevNode->next = nextNode;
        }

        delete curr;
    }

    // printing reverse
    void display()
    {
        Node<T> *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->val << ' ';
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{

    DoublyLinkedList<int> list;
    list.insert(12);
    list.insert(32);
    list.insert(34);
    list.display();
    list.deleteNode(12);
    list.display();

    return 0;
};