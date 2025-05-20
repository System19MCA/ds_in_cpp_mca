#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T coeff;
    T exp;
    Node *next;

    Node(T coeff, T exp)
    {
        this->coeff = coeff;
        this->exp = exp;
        next = nullptr;
    }
};

template <class T>
class Polynomail
{
    Node<T> *head;

public:
    Polynomail()
    {
        head = nullptr;
    }

    void insert(T coefficient, T exponent)
    {
        Node<T> *node = new Node<T>(coefficient, exponent);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->exp != 0)
            {
                if (temp->coeff == 1)
                {
                    cout << "x^" << temp->exp;
                }
                else
                {
                    cout << temp->coeff << "x^" << temp->exp;
                }
            }

            else
            {
                cout << temp->coeff;
            }
            temp = temp->next;
            if (temp != nullptr)
                cout << " + ";
        }
        cout << endl;
    }

    Polynomail operator+(Polynomail &list)
    {
        Polynomail<T> result;

        Node<T> *p1 = this->head;
        Node<T> *p2 = list.head;

        // Copy all terms from p1 list
        while (p1 != nullptr)
        {
            result.insert(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        // Add terms from p2 list, combining like terms
        while (p2 != nullptr)
        {
            Node<T> *resTemp = result.head;
            bool found = false;
            while (resTemp != nullptr)
            {
                if (resTemp->exp == p2->exp)
                {
                    resTemp->coeff += p2->coeff;
                    found = true;
                    break;
                }
                resTemp = resTemp->next;
            }
            if (!found)
            {
                result.insert(p2->coeff, p2->exp);
            }
            p2 = p2->next;
        }

        return result;
    }

    ~Polynomail()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            Node<T> *curr = temp->next;
            delete temp;
            temp = curr;
        }
        head = nullptr;
    }
};

int main()
{
    Polynomail<int> l1;
    l1.insert(2, 3);
    l1.insert(4, 2);
    l1.insert(6, 0);
    cout << "Polynomial 1: ";
    l1.display();

    Polynomail<int> l2;
    l2.insert(1, 4);
    l2.insert(4, 3);
    l2.insert(5, 0);
    cout << "Polynomial 2: ";
    l2.display();

    Polynomail<int> result = l1 + l2;
    cout << "Sum: ";
    result.display();

    return 0;
}
