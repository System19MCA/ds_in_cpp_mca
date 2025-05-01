#include <iostream>
using namespace std;

template <class T>
void quickSort(T *arr, int low, int high)
{
    T pivot = arr[low];
    int pivotIndex = low;
    if (high - low > 1)
    {
        int i = low + 1, j = high;
        while (j >= i)
        {
            if (arr[i] > pivot)
                swap<T>(arr[i], arr[j--]);
            else if (arr[i] < pivot)
            {
                swap<T>(arr[i], arr[pivotIndex]);
                pivotIndex = i++;
            }
            else
                i++;
        }
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int arr[] = {10, 20, 10, 5, 2, 7, 6, 4, 1};
    int size = sizeof(arr) / sizeof(int);
    quickSort<int>(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}