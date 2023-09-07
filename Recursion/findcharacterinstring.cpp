
#include<iostream>
#include<limits.h>
#include<string>

void findKey(char s[], char &key,int i,int &n){ //Taking & makes it a lttle faster and takes less space.Even eliminates TLE sometimes.
    if(i >= n) return;
    
    if(key == s[i]){
        std::cout<< i << "    is the index  "<<std::endl;//for all indices of the key is present multiple times
        
    }
    findKey(s,key,i+1,n);
    
}

int main(){
    char s[15] = "aditya pradhan";
    char key = 'a';
    int i = 0;
    int n = 15;
    findKey(s,key,i,n);
    
    
    
    
}