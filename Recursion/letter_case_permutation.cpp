#include<iostream>
using namespace std;

void letter_case(string ip,string op,int n,int i){
    //base case
    if(i >= n){
        cout<<op<<" ";
        return;
    }
    //agar number hain toh skip
    if( '0'<= ip[i] && ip[i] <= '9'){
    op.push_back((ip[i]));
    letter_case(ip,op,n,i+1);
    }
    else{
        letter_case(ip,op+(char)toupper(ip[i]),n,i+1);
        letter_case(ip,op+(char)tolower(ip[i]),n,i+1);
    }
return;
}

int main(int a){
    a = 10;
    string ip ="a1b2";
    string op = "";
    int n = ip.length();
    letter_case(ip,op,n,0);
    return a;
}