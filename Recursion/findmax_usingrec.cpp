#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
void findMax(int arr[],int n,int i,long& maxie){
    if(i>=n) {
        return;
    }

maxie = std::max(maxie,arr[i]);
    findMax(arr,n,i+1)
    // std::cout<<maxie;

}
int main(){
    int arr[10] = {2,3,4,5,56,67,7,7,6,5};
    int key;
    int i=0;
    int n=10;
    long maxie = INT_MIN;
    std::cin>>key;
    std::cout<<findMax(arr,n,i,maxie);
}