#include<iostream>
using namespace std;

void permutations_with_caseChange(string ip,string op,int n,int i){
    //base case
    if(i >= n){
        cout<<op<<" ";
        return;
    }
    op.push_back(toupper(ip[i]));
    permutations_with_caseChange(ip,op,n,i+1);
    op.pop_back();
    permutations_with_caseChange(ip,op+ip[i],n,i+1);
}

int main(int a){
     a = 10;
    string ip = "abcd";
    string op ="";
    int n = ip.length();
    permutations_with_caseChange(ip,op,n,0);
return a;
}