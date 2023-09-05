#include<iostream>
#include<bits/stdc++.h>
#include<cstddef>
using namespace std;
// void print(int n){//tail and head recursion
//     if (n == 0) return ;
//     print(n-1);
//     cout<<n<<endl;


// }//factorial
// int fact(int n){
//     if(n == 1) return 1;  
//     int f = n*fact(n-1);
//     return f;
    

//}
void arrayprint(int arr,int n){
    if(i = n) {
        return;
        }
    cout<<arr[i]<<" ";
    arrayprint(arr,n,i+1);

}

// int p2w(int n){ //power of two will do without pow function later
//     if (n == 0) return 1;
//     return 2*pow(2,n-1); 
// }


// void print_digits(int n){ //print digits of number 
//     if(n==0) {
//         return;
//     }
//     cout<<n%10<<endl;
//     print_digits(n/10);

// }
int main(){

// int n;
// cin>>n;
// print(n);
// cout<<fact(n);

// cout<<endl<<p2w(5);
int arr[6] = {1,3,4,5,5,6};
int i = 0;
int n=6;
cout<<arrayprint(arr,n,i);

// print_digits(1243);

}