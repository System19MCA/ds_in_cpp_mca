#include <iostream>

using namespace std;

template <class T>
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

template <class T>
void mergeSort(T *arr, int size, int left, int right)
{
    if (right > left)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, size, 0, mid);
        mergeSort(arr, size, mid + 1, right);
        combine<int>(arr, size, left, right);
    }
}

int main()
{
    cout << "Enter size of the array: ";
    int size, *arr;
    cin >> size;
    arr = new int[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    mergeSort<int>(arr, size, 0, size - 1);

    cout << "Sorted Array" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
}