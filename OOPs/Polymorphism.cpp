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

class Parent{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};
class Child : public Parent{
public:
    void speak(){//Runtime polymorphism -> Function overriding
        cout<<"Talking"<<endl;
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
Parent *child = new Child; //pointer is to parent class therfore it will speaking will be printed
child->speak();

//2d array using heap memory
int row = 3;
int col = 4;
int **arr = new int*[row];
for(int i = 0;i < row;i++){
    arr[i] = new int[col];
}
for(int i = 0; i < row;i++){
    for(int j = 0; j < col;j++) cout<<arr[i][j];
    cout<<endl;
}
//deallocation of the heap memeory
for(int i = 0; i < row;i++) delete []arr[i];//first deletion
delete []arr;//second deletion
// vector<vector<int>> arr(n,vector<int>(m,1));     row then vector column then initializer//just revising
}