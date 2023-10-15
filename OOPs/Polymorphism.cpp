#include<iostream>

using namespace std;

// class Solve{
//     public:
//         int sum(int a,int b) {
//             return a+b;
//             }
//         int sum(int a,int b,int c){ //Function overloading
//             return a + b + c;
//         }//sum is existing in multiple forms
//         void print(int a,int b){
//             cout<<this->sum(a,b)<<endl;
//         }
// };

//operator overloading
class Solve{
    public:
        int val;
            void operator + (Solve &obj2){
                int val1 = this->val;
                int val2 = obj2.val;
                cout<<val2-val1<<endl;
            }
};

class Maths{
    public:
        int val;
            int operator + (Maths &b){//remember the address
                int value1 = this->val;
                int value2 = b.val;
                return value1*value2;//same with multiplication here
            }
};
int main(){
Solve obj1,obj2;
obj1.val = 2;
obj2.val = 7;
obj1+ obj2; //obj1 + obj2 actually subtracts here as we made it do it

Maths a,b;
a.val = 10;
b.val = 11;
cout<<a+b;
}