
#include<iostream>
#include<limits.h>
#include<string>

void findKey(char s[], char &key,int i,int &n){
    if(i >= n) return;
    
    if(key == s[i]){
        std::cout<< i << "       is the index";
        
    }
    findKey(s,key,i+1,n);
    
}

int main(){
    char s[15] = "aditya pradhan";
    char key = 'n';
    int i = 0;
    int n = 15;
    findKey(s,key,i,n);
    
    
    
    
}