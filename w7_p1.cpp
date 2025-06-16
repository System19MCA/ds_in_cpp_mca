#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], pair<int,int> lowHigh) {
    int low = lowHigh.first, high = lowHigh.second;
    int pivot = arr[high];  
    int i = low - 1;        
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int size) {
    stack<pair<int,int>> stk;
    stk.push({0, size-1});
    
    while (!stk.empty()) {
        pair<int,int> p = stk.top(); stk.pop();
        int pivotIndex = partition(arr, p);
        if (pivotIndex - 1 > p.first) stk.push({p.first, pivotIndex-1});
        if (pivotIndex + 1 < p.second) stk.push({pivotIndex+1, p.second});
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    quickSortIterative(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}
