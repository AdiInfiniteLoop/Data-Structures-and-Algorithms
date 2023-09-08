#include<iostream>

bool checkSorted(int arr[],int n, int i){
    if(i == n - 1){ 
        return NULL;
    }

    if((arr[i] > arr[i+1])) return false;
    return checkSorted(arr,n,i+1);

}
int main(){
    int arr[] = {1,3,5,6,8,9};
    int n = 6;
    int i = 0;
    bool isSorted = checkSorted(arr,n,i);
    if (isSorted) std::cout<<" Sorted";
    else std::cout<<"Not Sorted";
}