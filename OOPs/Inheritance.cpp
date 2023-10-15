#include<iostream>
#include<string.h>
using namespace std;

class Parent{
    protected:  //when private: even getter function can't be used to access data member
        int age; 
        string name;
    Parent(){
        cout<<"Parent constructor is called"<<endl;
        this -> age = 21;
    }
    ~Parent(){
        cout<<"Parent deconstructor is called"<<endl;
    }
};

class Child1:protected Parent{//class child class name: (mode of inheritance) parent class name{ };
    public:
        void print(){
            cout<<this-> age<<endl;//if mode of inheritance is private || protected then it can be accessed within the class but not outside the class
            //therfore we use a getter function print() here.
        }
};
class Child2: protected Child1{
        public:
            void print(){//getter function
                cout<<this-> age<<" :2nd one ";
            }
};

int main(){
    Child1 *kid1 = new Child1;
    kid1->print();
    delete kid1;

    Child2 *kid2 = new Child2;
    kid2-> print();
    delete kid2;

}