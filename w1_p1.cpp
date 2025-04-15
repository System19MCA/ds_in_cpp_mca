#include <iostream>

using namespace std;

template <class T>
class List
{

    T *arr;
    bool *visited;
    int size;

public:
    List(int size = 10)
    {
        this->size = size;
        this->visited = new bool[size];
        this->arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
            this->visited[i] = false;
        }
    }

    void insertItem(T item, int position)
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
                throw exception();

            for (int i = curr; i > position; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[position] = item;
        }
    }

    bool deleteItem(T item)
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
        T item = arr[pos];
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

    void update(T item, int newVal)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == item)
                arr[i] = newVal;
    }

    // update at an index
    void updatePos(int pos, T item)
    {
        if (pos < 0 || pos >= size)
            throw exception();
        arr[pos] = item;
    }
};

int main()
{

    int arr[10];

    List<int> l1 = List<int>(10);
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