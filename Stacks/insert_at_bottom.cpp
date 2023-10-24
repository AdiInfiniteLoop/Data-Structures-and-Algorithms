#include<iostream>
#include<stack>
using namespace std;
/*
perform operations
recursion
backtrack
*/
void solve(stack<int> &s,int temp){
    //Base case
    if(s.empty()){
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    //recursion
    solve(s,temp);
    //backtracking
    s.push(top);
}
void insertAtbot(stack<int> &s,int &N){
    //Base Case
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    solve(s,temp);
    //backtrack

}   
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    int N = s.size();

    insertAtbot(s,N);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}