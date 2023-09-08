#include<iostream>
#include<string>
using namespace std;

void printSubseq(string str,string out,int i){
    if(i >= str.length()){ std::cout<<out<<endl;
return;
}
//for excluding the letters
printSubseq(str,out,i+1);//try to exclude first then include later 
//for including the string
 //inputting the string values in output file
printSubseq(str,out + str[i],i+1);
}

int main(){
//Subsequences of a string
string str= "abc";

printSubseq(str," ",0);
}

