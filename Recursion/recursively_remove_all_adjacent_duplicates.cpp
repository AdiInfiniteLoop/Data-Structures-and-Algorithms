#include<iostream>
using std::cin;
using std::cout;

std::string remove_duplicates(std::string &s,int n,int i,std::string &str){
    if(i >= n ) return str;
    if(s[i] != s[i+1]){
        str.push_back(s[i]);
    } 
    remove_duplicates(s,n,i+1,str);
    return str;
}

signed main(){
    std::string s = "aaxxxcfdgg";
    int n = s.length();
    std::string output = "";
    remove_duplicates(s,n,0,output);
    for(auto it : output) cout<<it;
}