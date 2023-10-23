#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int> s,int n){
    //Base Case

    if(n/2+1 == s.size()){
        cout<<"The middle element is : "<<s.top()<<endl;
        return;
    }
    int temp = s.top();
    s.pop();
    printMiddle(s,n);
    //backtracking
    s.push(temp);}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    int n = s.size();
    printMiddle(s,n);
}