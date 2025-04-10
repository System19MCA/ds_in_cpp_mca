#include <iostream>
using namespace std;

// template <class T>
// void swap_(T &a, T &b)
// {
//     T t = a;
//     a = b;
//     b = t;
// }

template <class T>
T *selectionSort(T arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap<int>(arr[i], arr[minIndex]);
    }
    return arr;
}

int main()
{
    int arr[5] = {2, 5, 4, 1, 0};
    selectionSort<int>(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ", ";
    }
}