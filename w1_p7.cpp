#include <iostream>

using namespace std;

template <class T>

T *bubleSort(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap<int>(arr[i], arr[j]);
        }
    }
    return arr;
}

int main()
{

    int arr[5] = {2, 5, 4, 1, 0};
    bubleSort<int>(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}