#include <iostream>

using namespace std;

template <class T>
class Search
{
public:
    int binarySearch(T arr[], int size, T target)
    {
        int start = 0, end = size - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    int linearSearch(T arr[], int size, T target)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == target)
                return i;
        }
        return -1;
    }
};
int main()
{

    int arr[5] = {4, 5, 7, 8, 9};
    Search<int> s;
    cout << s.binarySearch(arr, 5, 0);

    return 0;
}