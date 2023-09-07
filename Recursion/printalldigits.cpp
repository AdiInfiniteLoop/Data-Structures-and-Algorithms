#include<iostream>
void printDigits(int n){
    if(n == 0)
        return ;
    printDigits(n/10);//for printing reverese order ,, swap line 5 and line 6  
    std::cout<<n%10<<" is the digit"<<std::endl;

}
int main(){
    int n = 0025;   //In C++, when started with leading zero it is considered as an octal value
    if(n == 0) std::cout<<0; //Handling the edge case
    printDigits(n);
}