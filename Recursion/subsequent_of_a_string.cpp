#include<iostream>
#include<string>
using namespace std;

void printSubseq(string str,string out,int i){
    if(i >= str.length()){ std::cout<<out<<endl;
return;
}
//for excluding the letters
printSubseq(str,out,i+1);
//for including the string
out = out + str[i]; //inputting the string values in output file
printSubseq(str,out,i+1);
}

int main(){
//Subsequences of a string
string str= "abc";

printSubseq(str," ",0);
}

