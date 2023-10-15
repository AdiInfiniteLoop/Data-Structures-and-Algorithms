/*Data Hiding is done where the data members and member functions are encapsulated
Perfect encapsulation means all members are private.
Can be achieved using access modifiers and class concepts
*/
#include<iostream>
#include<string.h>
using namespace std;
class Person{
    private:
        int age;
        string name;
    int getter(){
        return this->age;
    }
    void setter(int age){
        this ->age = age;
    }
};//Perfect encapsulation
