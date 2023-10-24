#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
stack<char>st;
for(char itr: s){
if(itr == '('|| itr == '{' || itr == '[')
    st.push(itr);
else{
    if(!st.empty()){
        if(itr == ')' && st.top() == '(')
            st.pop();
        else if(itr == ']' && st.top() == '[')
            st.pop();
        else if(itr == '}' && st.top() == '{')
            st.pop();
        else return false;
    }
    else    return false;
    
}
}

if(st.empty()) return true;
else return false;
}

void print(stack<char> &s){
    while(!s.empty()){
        cout<<s.top()<<"    ";
        s.pop();
    }
}
int main(){
    string s = "{[{}]}";
    cout<<isValid(s);

}