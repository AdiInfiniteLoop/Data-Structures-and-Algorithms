#include<iostream>
#include<stack>
using namespace std;

void printstack(stack<int> st){
        while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
void insert(stack<int> &st,int temp){
    if(st.size() == 0 || st.top() >= temp){
        st.push(temp);
        return;
    }
    int last_ele = st.top();
    st.pop();
    insert(st,temp);
    st.push(last_ele);
}
void sort(stack<int> &st){
    if(st.size() == 0 )
        {
            return;
        }
    int temp = st.top();
    st.pop();
    sort(st);
    insert(st,temp);
}
signed main(){
    stack<int> st;
    st.push(7);
    st.push(8);
    st.push(73);
    st.push(2);
    st.push(1);
  
sort(st);    
printstack(st);   
}