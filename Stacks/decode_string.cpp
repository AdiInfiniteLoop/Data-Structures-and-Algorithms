#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> currstr;
    stack<int> currnum;
    string str = "a3[df]f";
    for(char itr: str){
        if(itr >= '1' && itr <= '9')
            currnum.push(itr);
        else currstr.push(itr);
        if(itr == ']'){
            while(itr != '['){
                temp += itr;
                s.pop();
            }
        }

    }
}