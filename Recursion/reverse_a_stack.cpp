#include<iostream>
#include<stack>

using namespace std;
void printstack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}
void insert(stack<int> &st,int temp){
    if(st.size() == 0){
        st.push(temp);
        return;
    }
    int ele = st.top();
    st.pop();
    insert(st,temp);
    st.push(ele);
    return;
}

void reverseStack(stack<int> &st) {
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();

    reverseStack(st); 
    insert(st,temp);
}
int main(){
    stack<int> st;
       st.push(1);
   st.push(164);
   st.push(16);
   st.push(11);
   st.push(7);
   st.push(3);  
   st.push(1);
   st.push(5);
   st.push(16);
   st.push(6);
   st.push(74);
   st.push(23);

    reverseStack(st);
   printstack(st);
}