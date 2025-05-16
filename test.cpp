#include <iostream>

using namespace std;

class Matrix
{
    int *arr;
    int rows, cols;
    int size;

public:
    Matrix(int size)
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
        this->size = size;
    }

    friend ostream &operator<<(ostream &os, Matrix &mat);
};

ostream &operator<<(ostream &os, Matrix &mat)
{
    os << "[";
    for (int i = 0; i < mat.size; i++)
    {
        os << mat.arr[i] << " ,";
    }
    os << "]";
    return os;
}

int main()
{
    Matrix m1(5);
    cout << m1;
    return 0;
}