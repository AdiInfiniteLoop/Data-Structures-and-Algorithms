#include<iostream>
void printDigits(int n){
    if(n == 0)
        return ;
    printDigits(n/10);
    std::cout<<n%10<<" is the digit"<<std::endl;

}
int main(){
    int n = 132124;
    printDigits(n);
}