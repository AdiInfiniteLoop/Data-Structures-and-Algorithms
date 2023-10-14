#include<iostream>
#include<string.h>

using namespace std;
class Animal{
    public:
int age;
char ch;
    void sleep(){
cout<<"Sleeping function called"<<endl;
    }
};


class Person{

private:
    int weight;
public:
    //State
    int age;
    string name;

    //Behaivour/Functions in C++ and metods in Java/
    void eat(){
cout<<"EAting function called"<<endl;
    }

    void sleep(){
cout<<"Sleeping function called"<<endl;
    }
    //The getter and setter function should be called inside public access modifier
    int getter(){
        return weight;
    }
    void setter(int weight){
        //weight = weight; gives garbage value....therefore we use this keyword
        this->weight = weight;//works perfectly....'this' is a pointer to the current object
    }
    //Constructor
    Person(){
        cout<<"Constructor called"<<endl;
        this -> age = 0;//initialized //using this -> is a good practice but can even use age, name normally
        this -> name = ""; //initialized
    }

    Person(int age){
        cout<<"Paramaeterized cinstrucotr is called"<<endl;
        this ->age = age;
      

}  //Copy constructor
    Person(Person &Pradhan){
            cout<<"Copy constructor is created"<<endl;
            this -> age =  Pradhan.age;
            this -> name = Pradhan.name;
        }

};

class Car{
    public:
    //called default Constructor
    Car(){
        cout<<"Constructor called again"<<endl;
    }
    //Destructor
    ~Car(){
        cout<<"Destructor is called "<<endl;    }
};

int main(){
    std::cout<<"Size of an empty class is "<<sizeof(Animal)<<endl; // the output comes 8 rather than 5 ;;Study Padding and greedy alignment
    //Object creation from person class
    // 1.Static allocation
        Person Aditya;
        cout<<"Age of Aditya is: "<<Aditya.age<<endl;//before initialization in main() due to default constructor
        Aditya.age = 15;
        Aditya.name = "Aditya Pradhan";
        cout<<"Age of Aditya is: "<<Aditya.age<<endl;
        cout<<"Name of Person is: "<<Aditya.name<<endl;
        Aditya.eat();
        Aditya.sleep();

        //Getter and setter
        Aditya.setter(80);
        cout<<Aditya.getter()<<endl;
    // 2.Dynamic memory allocation
        Animal *Adi = new Animal;//int * pre = new int ||int * ptr = new int[5]
        // Adi.age = 12; causes error because Adi stores the address not the object itself
        Adi->age = 20;
        Adi -> sleep();
        (*Adi).sleep();

Car car;
Car *car2 = new Car();//Constructor is by default called whenever an object is create
Car *car3 = new Car; //all are correct


Person *Pradhan = new Person(100);//Parameterized constructor is called
Person d;
d.age = 10;
Person a = d;//copy constructotr is created
cout<<a.age;//The value of age is copied
Person person(d);//other way to create copy constructor

delete car2;//Manually calling destructor
delete car3;
}