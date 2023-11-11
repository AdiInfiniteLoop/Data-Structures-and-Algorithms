#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
int main(){
    std::string str1 = "345";
    std::string str2 = "653";
    int ans = std::stoi(str1) + std::stoi(str2);
    
    std::cout<<ans;
}