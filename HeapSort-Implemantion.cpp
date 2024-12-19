#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  }
}


void buildMaxHeap(vector<int>& arr, int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    buildMaxHeap(arr, n);


    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}


int main() {
    vector<int> arr = {7,12,16,18,19,61};

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
