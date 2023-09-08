#include<iostream>
bool checkSorted(int *arr,int n){
    if(n <= 1) return true;

    if(arr[n-2] > arr[n-1]) return false;

    return checkSorted(arr,n-1);   
}

int main(){
int arr[] = {1,2,4,5,6,7,8,9};
int n = 8;

if(checkSorted(arr,n) == true)   
    std::cout<<"Sorted";
else
std::cout<<"Not sorted";
}