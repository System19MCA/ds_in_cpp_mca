#include <iostream>

using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int coeff, int exp)
    {
        this->coeff = coeff;
        this->exp = exp;
        next = nullptr;
    }
};

class Polynomail
{
    Node *head;

public:
    Polynomail()
    {
        head = nullptr;
    }

    void insert(int coefficient, int exponent)
    {
        Node *node = new Node(coefficient, exponent);

        // Case 1: Empty list or insert at beginning
        if (head == nullptr || head->exp < exponent)
        {
            node->next = head;
            head = node;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        // intraverse to find correct position
        while (temp != nullptr && temp->exp >= exponent)
        {
            if (temp->exp == exponent)
            {
                // Combine like terms
                temp->coeff += coefficient;
                delete node;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        // Insert in the middle or at the end
        node->next = temp;
        prev->next = node;
    }

    void display()
    {
        Node *temp = head;
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
        Polynomail result;

        Node *p1 = this->head;
        Node *p2 = list.head;

        // Copy all terms from p1 list
        while (p1 != nullptr)
        {
            result.insert(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        // Add terms from p2 list, combining like terms
        while (p2 != nullptr)
        {
            Node *resintemp = result.head;
            bool found = false;
            while (resintemp != nullptr)
            {
                if (resintemp->exp == p2->exp)
                {
                    resintemp->coeff += p2->coeff;
                    found = true;
                    break;
                }
                resintemp = resintemp->next;
            }
            if (!found)
            {
                result.insert(p2->coeff, p2->exp);
            }
            p2 = p2->next;
        }

        return result;
    }

    Polynomail &operator*(Polynomail &obj){
        Polynomail *result = new Polynomail();
           
        Node *p1 = this->head;
        Node *p2 = obj.head;

        while (p1 != nullptr)
        {             
            Node *curr = p2;
            while (curr !=nullptr)
            {               
                int coeff =p1->coeff * curr->coeff;
                int exp =  p1->exp + curr->exp;
                result->insert(coeff,exp);
                curr= curr->next;
            }
            p1= p1->next;
            
        }

        return *result;
        

    }
    ~Polynomail()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *curr = temp->next;
            delete temp;
            temp = curr;
        }
        head = nullptr;
    }
};

int main()
{
    Polynomail l1;
    l1.insert(2, 3);
    // l1.insert(6, 0);
    l1.insert(4, 2);
    cout << "Polynomial 1: ";
    l1.display();

    Polynomail l2;
    l2.insert(1, 4);
    l2.insert(4, 3);
    // l2.insert(5, 0);
    cout << "Polynomial 2: ";
    l2.display();

    Polynomail result = l1 * l2;
    cout << "Sum: ";
    result.display();

    return 0;
}
