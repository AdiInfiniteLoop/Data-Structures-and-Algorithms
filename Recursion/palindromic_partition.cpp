#include<iostream>
#include<cstring>
#include<vector>
bool ispalindrome(std::string& str,int ind){
int i = ind, j = str.size() - 1;
while(i <= j){
    if(str[i] != str[j]) {
        return false;
        break;
    }
    else {
        i++,j++;
    }
    return true;
}

}
void palinsubstring(std::string& str,int ind){
    std::vector<std::string> v;
    int n = str.size();
    if(ind == n) return;
    for(ind ;ind < n;ind++){
        if(ispalindrome(str,ind)){
            v.push_back()
        }
    }

}
int main(){
    std::string str = "aabb";
}