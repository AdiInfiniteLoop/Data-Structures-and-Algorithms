#include<iostream>
using namespace std;

void heapify(int *arr, int n, int i) {
    int largest = i;
    while(true){
        int left = 2*i;
        int right = 2*i+1;
        if(arr[left] > arr[i] && left < n)largest = left;
        if(arr[right] > arr[i] && right < n)largest = right;

        if(i != largest){
            swap(arr[i],arr[largest]);
            i = largest;
        } else{
            break;
        }
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; --i) {  // Start from 0 instead of 1
        heapify(arr, n, i);
    }
}


void heapSort(int * arr, int n){
    
    while(n != 1){
        swap(arr[1],arr[n--]);
        heapify(arr,n,1);
    }
    
}

int main() {
    int *arr = new int[13] {-1,5,2,3,1};  // Allocate memory for 13 elements
    int n = 4;

    buildHeap(arr, n);

    for (int i = 1; i <= n; ++i) {
        cout << " " << arr[i] << " ";
    }

    heapSort(arr,n);
    cout<<"\n";
    for (int i = 1; i <= n; ++i) {
        cout << " " << arr[i] << " ";
    }


    return 0;
}




//do the same code for 0based Indexing