#include<iostream>
using namespace std;

void permutations(string ip,string op, int n,int i){
    //base case
    if(i >= n){
        cout<<op<<" ";
        return;
    }
    permutations(ip,op+"_"+ip[i],n,i+1);
    permutations(ip,op+ip[i],n,i+1);
}
int main(){
    string ip = "abc";
    string op ="";
    op += ip[0];
    permutations(ip,op,ip.length(),1);
}