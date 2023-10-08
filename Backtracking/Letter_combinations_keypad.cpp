#include<iostream>
#include<vector>
#include<string.h>


void solve(std::vector<std::string> &map,std::vector<std::string> &ans,int ind, std::string str, std::string out){
//Base Case
if(ind >= str.length()){
    ans.push_back(out);
    return;
}
char digit = str[ind];
std::string value = map[digit];
for(int i = 0; i < value.length();i++){
    char ch = value[i];
    out.push_back(ch);
    solve(map,ans,ind+1,str,out);
    out.pop_back(); //Backtracking statement
}

}
int main(){
    std::string str = "99";
    std::string out = "";
    std::vector<std::string> map(10);
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    std::vector<std::string> ans;
    solve(map,ans,0,str,out);
for(auto itr : ans)std::cout<<itr<<" ";
    }