#include<iostream>
#include<stack>
using namespace std;
void insertattarget(stack<int> &s,int &target){
    //Base Case
    if(s.empty()) {
        s.push(target);
        return;
    }

    if(s.top() >= target){
        s.push(target);
        return;
    }

    int ele = s.top();
    s.pop();
    insertattarget(s,target);
    s.push(ele);
}
void sort(stack<int> &s){
    //Base Case
    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    sort(s);
    insertattarget(s,top);

}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}