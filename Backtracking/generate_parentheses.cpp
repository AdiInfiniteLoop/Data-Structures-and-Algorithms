#include<iostream>
#include<vector>
#include<string.h>

void solve(std::vector<std::string> &ans, int &n, int open , int close, std::string out){
    //Base Case
    if(open <= 0 && close <= 0){
        ans.push_back(out);
        return;
    }
    //Include open brackets
     if(open > 0){
        out.push_back('(');
        solve(ans,n,open - 1,close,out);
        out.pop_back(); //Backtrack
     }
     if(close > open)//The number of closing brackets shoulf be more than open brackets
     {
        out.push_back(')');
        solve(ans,n,open,close -1,out);
        out.pop_back();
     }
}
int main(){
    std::vector<std::string> ans;
    int n = 2; 
    int open = n;
    int close = n;
    std::string out = "";
    solve(ans,n,open,close,out);
    for(auto itr : ans) std::cout<<itr<<" ,";
}