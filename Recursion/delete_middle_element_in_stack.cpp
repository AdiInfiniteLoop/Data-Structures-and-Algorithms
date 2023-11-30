#include<iostream>
#include<stack>
using namespace std;

void printstack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

void delete_middle(stack<int> &st,int k){
    //base case
    
    //hypothesis:delete middle element
    //induction:keep poping and reducing k with 1 value

}
int main(){
   stack<int> st;
   st.push(1);
   st.push(164);
   st.push(16);
   st.push(11);
   st.push(7);
   st.push(3);
    printstack(st);
    delete_middle(st,st.size());
    printstack(st);
    

}