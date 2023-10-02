#include<iostream>
#include<string.h>

void stringpermutations(std::string &str, int i){    //When we add &str we require backtracking here
                                                    //But if we make a string copy without & operator ,the permutations are printed just fine
    if(i >= str.length()){
        std::cout<<str<<"\n";
        return;
    }
    for(int j = i;j < str.length();j++){
        //Swapping the letters
        std::swap(str[j],str[i]);
        //recursive call
        stringpermutations(str,i+1);//Don't use i++.Will cause segemntation fault:core dumped
        //Backtracking
        std::swap(str[j],str[i]);//to recreate the original input necessary because string is passed by reference
        //Therefore if "acb" is formed from "abc" we will re-swap it for original input.
    }
}
int main(){
    std::string str = "abc";
    stringpermutations(str,0);
}