#include <iostream>
#include <vector>
using namespace std;

// Max Heap class
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size() && heap[left] > heap[largest])
            largest = left;
        if (right < size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    int size() { return heap.size(); }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(size() - 1);
    }

    int extractMax() {
        if (size() == 0) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
        return root;
    }

    void display() {
        cout << "Max Heap: ";
        for (int v : heap)
            cout << v << " ";
        cout << "\n";
    }
};

// Min Heap class
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    int size() { return heap.size(); }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(size() - 1);
    }

    int extractMin() {
        if (size() == 0) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
        return root;
    }

    void display() {
        cout << "Min Heap: ";
        for (int v : heap)
            cout << v << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap;
    MinHeap minHeap;

    int elements[] = {20, 15, 30, 40, 50, 10, 5};

    cout << "Inserting elements:\n";
    for (int val : elements) {
        cout << val << " ";
        maxHeap.insert(val);
        minHeap.insert(val);
    }
    cout << "\n\n";

    maxHeap.display();
    minHeap.display();

    cout << "\nExtracting from Max Heap: " << maxHeap.extractMax() << "\n";
    maxHeap.display();

    cout << "Extracting from Min Heap: " << minHeap.extractMin() << "\n";
    minHeap.display();

    return 0;
}
