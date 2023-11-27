#include<iostream>
using std::cin;
using std::cout;

void fastIO(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
}
void reversearray(int *arr,int n,int ind){
if(ind < n) {
std::swap(arr[ind],arr[n]);
reversearray(arr,n-1,ind+1);
}
else return;
}

signed main(){
fastIO();
int arr[] = {10,20};
int n  = 2;
reversearray(arr,n-1,0);
for(int i = 0; i< n;i++) cout<<arr[i] <<" ";
}