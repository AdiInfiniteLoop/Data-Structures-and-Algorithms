#include<iostream>
using namespace std;

class Solve{
public:
    int value;
    int operator + (Solve &b){
        int val1 = this->value;
        int val2 = b.value;
        return abs(val2-val1);
    }
);

int main(){
    //object creation
    Solve a,b;
    a.value = 14;
    b.value = 432;
    cout<<a + b;
}