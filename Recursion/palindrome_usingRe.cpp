#include<iostream>
#include<cstring>

bool palindromiccheck(std::string& str, int n,int i){
    if(i >= n) return true;

    if(str[i] != str[n]) return false;
    return palindromiccheck(str,n-1,i+1);
}
int main(){
    std::string str;
    getline(std::cin,str);
    int n = str.size() - 1;
    bool isPalin = palindromiccheck(str,n,0);
    std::cout<<isPalin;
}