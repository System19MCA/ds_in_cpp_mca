#include <iostream>

using namespace std;

class List
{

    int *arr;
    bool *visited;
    int size;

public:
    List(int size = 10)
    {
        this->size = size;
        this->visited = new bool[size];
        this->arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
            this->visited[i] = false;
        }
    }

    void insertItem(int item, int position)
    {

        if (position < 0 || position >= size)
        {
            throw exception();
        }

        if (!this->visited[position])
        {
            arr[position] = item;
            visited[position] = true;
        }
        else
        {
            int curr = position;
            while (visited[curr] && curr < size - 1)
                curr++;

            if (curr >= size)
                throw exception(); // no vacancy for jkssb

            for (int i = curr; i > position; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[position] = item;
        }
    }

    bool deleteItem(int item)
    {
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == item)
            {
                arr[i] = 0;
                visited[i] = false;
                flag = true;
            }
            else
            {
                return false;
            }
        }
        return flag;
    }

    int deletePos(int pos)
    {

        if (pos < 0 || pos >= size)
            throw exception();
        int item = arr[pos];
        this->arr[pos] = 0;
        this->visited[pos] = false;
        return item;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }

    // updates all elements
    void update(int item, int newVal)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == item)
                arr[i] = newVal;
    }

    // update at an index
    void updatePos(int pos, int item)
    {
        if (pos < 0 || pos >= size)
            throw exception();
        arr[pos] = item;
    }
};

int main()
{

    int arr[10];

    List l1 = List(10);
    // l1.display();
    l1.insertItem(12, 0);
    l1.insertItem(1, 1);
    l1.insertItem(2, 3);
    l1.display();
    l1.insertItem(5, 3);
    l1.display();

    l1.deleteItem(1);
    l1.deletePos(3);

    l1.display();

    return 0;
}