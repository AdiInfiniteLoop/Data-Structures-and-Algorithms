#include<iostream>
#include<vector>
//ye toh pakka backtracking hain
using namespace std;

void solve(vector<string> &ans,string op,int open,int close){
    if(open <= 0 && close <= 0){
        ans.push_back(op);
        return;
    }
    if(close > open ){
        op.push_back(')');
        solve(ans,op,open,close-1);
        op.pop_back();
    }
    if(open > 0){
        op.push_back('(');
        solve(ans,op,open - 1,close);
        op.pop_back();

    }
    return ;
}


int main(){
    int n = 3;
    vector<string> ans;
    string op = "";
    int open = n,close = n;
    solve(ans,op,open,close);
    for(auto i: ans) cout<<i<<" ";
}