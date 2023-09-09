#include<iostream>
#include<cstring>
void reversestr(std::string& str,int n,int i){
    if(i >= n) return;
    std::swap(str[i],str[n]);
     reversestr(str,n-1,i+1);
}
int main(){
    std::string str;
    getline(std::cin,str);
    int n = str.size() - 1;
reversestr(str,n,0);
std::cout<<str;
}