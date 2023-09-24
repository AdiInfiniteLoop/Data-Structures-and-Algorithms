#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& arr, int left, int mid, int right) {
  // Create two temporary arrays to store the sorted halves of the input array.
  vector<int> leftArr(mid - left + 1);
  vector<int> rightArr(right - mid);
  // Copy the elements of the input array into the temporary arrays.
  for (int i = 0; i < leftArr.size(); i++) {
    leftArr[i] = arr[left+i];
  }
  for (int i = 0; i < rightArr.size(); i++) {
    rightArr[i] = arr[mid + 1 + i];
  }
  // Merge the two sorted arrays back into the input array until one array is exhausted.
  int i = 0, j = 0, k = left;
  while (i < leftArr.size() && j < rightArr.size()) {
    if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
    else arr[k++] = rightArr[j++];
}

  // Copy the remaining elements of the left array into the input array.
  while (i < leftArr.size()) 
    arr[k++] = leftArr[i++];

  while (j < rightArr.size()) {
    arr[k++] = rightArr[j++];
}

}
void mergeSort(vector<int>& arr, int left, int right) {
  if (left < right){
    
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  
  }
  else return;  //Base Case
}

int main() {
    vector<int> arr{2,34,5,6,7,8,9,9};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

  cout << endl;

  return 0;
}