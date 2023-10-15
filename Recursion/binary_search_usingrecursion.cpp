#include<iostream>

void binarys(int *v, int s, int e, int key){
    if(s > e) return;
    int mid = s + (e - s)/2;

    if (key == v[mid]) std::cout<<mid;
    ////cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’ ....to tackle this problem we use s = mid + 1 and e = mid - 1  
    return (key > v[mid]) ? binarys(v,mid + 1,e,key) :binarys(v,s,mid - 1,key); //Using ternary operator 
}

int main(){
   int v[] = {1,2,4,5,6,8,9,10,12};
    int key;
    std::cin>>key;
    int n = 9;
    int s = 0, e = 8;
    binarys(v,s,e,key);
    
}