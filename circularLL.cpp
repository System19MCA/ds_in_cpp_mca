#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node *next;

    Node(T val)
    {
        this->val = val;
        next = nullptr;
    }
};

template <class T>
class CircularLinkedList
{
    Node<T> *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insert(T val)
    {
        Node<T> *node = new Node(val);
        if (head == nullptr)
        {
            head = node;
            node->next= head;
            return;
        }

        if (head->next == nullptr)
        {
            head->next = node;
            node->next = head;
            return;
        }

        Node<T> *temp = head->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = node;
        node->next = head;
    }

    void display()
    {
        if(head!= nullptr ){
            cout << head->val << ' ';
           
        }

        Node<T> *temp = head->next;
        while (temp != head)
        {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    CircularLinkedList <int> list;
    list.insert(55);
    list.insert(32);
    list.insert(32);
    list.insert(32);
    list.display();

    return 0;
};