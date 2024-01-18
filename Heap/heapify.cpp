#include<iostream>
using namespace std;

void heapify(int *arr, int n, int i) {
    int index = i;
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= n && arr[index] < arr[left]) largest = left; //left <= n is imp/\.
    if (right <= n && arr[largest] < arr[right]) largest = right;

    if (index != largest) {
        std::swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    } 
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 0; --i) {  // Start from 0 instead of 1
        heapify(arr, n, i);
    }
}

int main() {
    int *arr = new int[13] {-1, 76, 45, 3, 4, 86, 42, 35, 87, 98 ,43 ,23 ,12};  // Allocate memory for 13 elements
    int n = 10;

    buildHeap(arr, n);

    for (int i = 1; i <= n; ++i) {
        cout << " " << arr[i] << " ";
    }

    // Don't forget to free the allocated memory
    delete[] arr;

    return 0;
}
