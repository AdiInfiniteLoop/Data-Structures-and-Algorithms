#include<iostream>
#include<stack>
using namespace std;

void insertatbot(stack<int> &s,int temp){
    //base case
    if(s.empty()){
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    insertatbot(s,temp);
    s.push(top);

}
void reverse(stack<int> &s){
    //Base case

    if(s.empty()){
        return;
    }
    int ele = s.top();
    s.pop();
    reverse(s); 
    insertatbot(s,ele);
}
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
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
    print(s);
    reverse(s);
    cout<<"\nThe reversed stack is: \n";
    print(s);
}

/*Empty the stack push the first element from the prev function and use the new function to insert at the bottom*/