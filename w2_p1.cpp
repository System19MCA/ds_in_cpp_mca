#include <iostream>

using namespace std;

template <class T>
class Sort
{
    void combine(T *arr, int size, int left, int right)
    {
        if (right <= left)
            return;
        int mid = (left + right) / 2;
        int first = left, second = mid + 1, i = 0;
        T *temp = new T[right - left + 1];
        while (first <= mid && second <= right)
        {
            if (arr[first] < arr[second])
                temp[i++] = arr[first++];
            else
                temp[i++] = arr[second++];
        }
        while (first <= mid)
            temp[i++] = arr[first++];
        while (second <= right)
            temp[i++] = arr[second++];

        for (int j = 0; j <= right - left; j++)
            arr[left + j] = temp[j];
    }
    void mergeSort(T *arr, int size, int left, int right)
    {
        if (right > left)
        {
            int mid = (left + right) / 2;
            mergeSort(arr, size, 0, mid);
            mergeSort(arr, size, mid + 1, right);
            combine(arr, size, left, right);
        }
    }

public:
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

    void mergeSort(T *arr, int size)
    {
        mergeSort(arr, size, 0, size - 1);
    }
};

int main()
{
    int arr[5] = {2, 5, 4, 1, 0};
    int size = 5;
    Sort<int> s;
    s.mergeSort(arr, size);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ", ";
    }
}