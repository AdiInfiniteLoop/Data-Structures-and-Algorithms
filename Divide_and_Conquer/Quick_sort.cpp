#include <iostream>

int partition(int *arr, int start, int end)
{
    //Finding the pivot element
	int pivot = arr[start];
    int pivotIndex = start;
    //Find the correct place for pivot element
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position using start
	pivotIndex = start + count;//Example, if there are 5 people in a line shorter than me then i will stand at 6th place(currentind + smaller people)
	std::swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
        //Keep moving the pointers
		while (arr[i] <= pivot) i++;
		
		while (arr[j] > pivot)	j--;
		
		if (i < pivotIndex && j > pivotIndex) { //The index i and j should be less and greater repectively
			std::swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int pivotIndex = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, pivotIndex - 1);

	// Sorting the right part
	quickSort(arr, pivotIndex + 1, end);
}

int main()
{
	int arr[] = { 9, 3, 4, 2, 1, 8 ,5,7,7,8,9,9,0,0,0,0,9,7,54,4,4,57,6,75,56};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) 
		std::cout << arr[i] << " ";

	return 0;
}
