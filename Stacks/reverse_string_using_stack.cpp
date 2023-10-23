#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    string str;
    getline(cin,str);
    cout<<"The original string is: "<<str<<endl;
    for(int i = 0;i< str.size();i++){
        s.push(str[i]);
    }
    cout<<"The reversed string is: ";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}