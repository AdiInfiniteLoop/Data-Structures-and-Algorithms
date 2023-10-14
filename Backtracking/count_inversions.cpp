#include<iostream>

bool isSafe(int arr[5],int i,int k){
    if(arr[i] > arr[k]) return true;
    return false;
}
int countinversions(int arr[5],int n,int i,int count){
    //Base Case
    if(i == n){
        return count;
    }
    for(int k = 0; k < n;k++){
        if(isSafe(arr,i,k)){
            count++;
        }
        countinversions(arr,n,i++,count);
    }
}
int main(){
    int arr[5] = {5,3,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countinversions(arr,n,0,0);
}