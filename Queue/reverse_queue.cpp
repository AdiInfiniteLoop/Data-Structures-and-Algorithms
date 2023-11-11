#include<iostream>
#include<queue>
#include<stack>

using std:: cout;
using std::endl;
static void Print(std::queue<int> q){

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverse(std::queue<int> &q){
    //Base case
    if(q.empty()) {
        return;
    }
    int t = q.front();
    q.pop();
    reverse(q);
    q.push(t);
}
int main(){
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<"Before reversing ";
    Print(q);
    cout<<endl;
    // std::stack<int> st;
    // while(!q.empty()){
    //     st.push(q.front());
    //     q.pop();
    // }
    // cout<<"After reversing ";
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    reverse(q);
    cout<<"After reversing "; 
    Print(q);
}