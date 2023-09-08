#include<iostream>
#include<vector>

void binarys(int v[], int s, int e, int &key){
    if(s > e) return;
    int mid = s + (e - s)/2;

    if (key == v[mid]) std::cout<<mid;
    if(key > v[mid])binarys(v,mid + 1,e,key);
    else if(key < v[mid]) binarys(v,s,mid - 1,key);
}

int main(){
   int v[] = {1,2,4,5,6,8,9,10,12};
    int key;
    std::cin>>key;
    int n = 9;
    int s = 0, e = 8;
    binarys(v,s,e,key);
}