#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node *next;

    Node(T value)
    {
        val = value;
        next = nullptr;
    }
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insertAtEnd(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (head == nullptr)
            head = node;
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    void insertAtBeginning(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (head == nullptr)
            head = node;
        else
        {
            node->next = head;
            head = node;
        }
    }

    void insertAfter(T target, T value)
    {
        Node<T> *node = new Node<T>(value);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node<T> *curr = head;
        while (curr != nullptr)
        {
            if (curr->val == target)
            {
                Node<T> *temp = curr;
                curr = curr->next;
                temp->next = node;
                node->next = curr;
                return;
            }
            curr = curr->next;
        }
    }

    void insertAfterNode(T num, T value)
    {
        int count = 0;
        Node<T> *node = new Node<T>(value);
        Node<T> *curr = head;
        while (curr != nullptr)
        {

            if (count == num)
            {
                Node<T> *temp = curr;
                curr = curr->next;
                temp->next = node;
                node->next = curr;

                return;
            }
            count++;
            curr = curr->next;
        }
        throw exception();
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
            throw exception();

        if (head->val == value)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> *prev = nullptr;
        Node<T> *curr = head;
        while (curr != nullptr)
        {

            if (curr->val == value)
            {
                Node<T> *temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void deleteNodeAtBeginning()
    {
        if (head == nullptr)
            throw exception();

        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    void deleteNodeAtEnd()
    {
        if (head == nullptr)
            throw exception();

        Node<T> *prev = nullptr;
        Node<T> *curr = head;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        if (prev != nullptr)
            prev->next = nullptr;
        else
            head = nullptr;
    }

    void display()
    {
        if (head == nullptr)
            throw exception();
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList<int> list;
    list.insertAtEnd(15);
    list.insertAtEnd(23);
    list.insertAtEnd(32);
    // list.display();
    // list.insertAtBeginning(45);
    // list.insertAfter(45, 42);
    // list.insertAfterNode(2, 67);
    list.display();
    // list.deleteNode(15);
    // list.deleteNodeAtBeginning();
    list.deleteNodeAtEnd();
    list.deleteNodeAtEnd();
    // list.deleteNodeAtEnd();
    list.display();

    return 0;
}
