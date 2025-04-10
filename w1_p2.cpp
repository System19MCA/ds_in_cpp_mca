#include <iostream>

using namespace std;

template <class T>
int find(T arr[], int size, T target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 43};

    cout << find(arr, sizeof(arr) / sizeof(int), 20) << endl;

    return 0;
}