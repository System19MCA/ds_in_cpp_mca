#include <iostream>

using namespace std;

template <class T>
T *insertionSort(T *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
    return arr;
}

int main()
{
    int arr[5] = {2, 5, 4, 1, 0};
    insertionSort<int>(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ", ";
    }
}