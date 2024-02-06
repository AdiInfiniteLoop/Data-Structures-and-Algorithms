#include<iostream>
#include<valarray> //Check this header file
bool checkSorted(int arr[],int n){ //Can also take int *arr 
    if(n <= 1) return true; //To check if the array has 0 or 1 element making it already sorted
    if(arr[n-2] > arr[n-1]) return false;

    return checkSorted(arr,n-1);   
}

int main(){
int arr[] = {3,1,2,4,4};
int n = 5;

if(checkSorted(arr,n) == true)   
    std::cout<<"Sorted";
else
std::cout<<"Not sorted";
}
