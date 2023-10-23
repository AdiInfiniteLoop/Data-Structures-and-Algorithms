#include<iostream>
#include<stack>
using namespace std;

// class Stack{
// private:    //abstraction here only necessary data is shown
//         int size;
//         int top;
//         int* arr;
//     public:
//         Stack(){
//             this->size = size;
//             this->top = -1;
//             arr = new int[size];
// }
//         Stack(int size){
//             this->size = size;
//             this->top = -1;
//             arr = new int[size];//no need for int arr as arr is already int decalred previously
//         }
//         //functions/behaivour
//         void push(int data){
//             if(size - top > 1) {
//                 arr[++top] = data;  //use ++top rather than top++ as we gotta move top from -1 position first
//             }
//             else cout<<"Stack Overflowed";
//         }
//         void pop(){
//             if(top <= -1) cout<<"Stack Underflowed";
//             else top--;
//         }
//         int getSize(){//returns number of valid elements present
//             return top + 1;
//         }
//         int getTop(){
//             int element;
//             if(top == -1)cout<<"Not a valid index";
//             else {
//                 element =  arr[top];
//             }
//             return element;
//         }
//         bool empty(){
//             if(top == -1) return true;
//             else return false;
//         }
// };
class Stack{
private:
    int size; 
    int top1;
    int top2;
    int *arr;
    public:
        Stack(int size){
            this->size = size;
            this->top1 = -1;
            this->top2 = size;
            arr = new  int[size];
        }

        void push1(int s){
            if(top2- top1 > 1) arr[++top1] = s;
            else cout <<"Stack1 over flowed\n"<<endl;
        }
        void push2(int data){
            if(top2 - top1 == 1) cout<<"Space unavailable for stack2\n";
            else arr[--top2] = data;
        }
        void pop1(){
            if(top1 == -1) cout<<"Empty Stack1\n";
            else {
                arr[top1] = 0;
                top1--;
            }
        }
        void pop2(){
            if(top2 == size) cout<<"Empty Stack2\n";
            else {
                arr[top2] = 0;
                top2++;
            }
        }
        void print(){
            for(int i = 0;i < size;i++)
            cout<<arr[i]<<" ";
            cout<<endl;
        }

};
int main(){
    // std::stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // std::cout<<s.top()<<std::endl;
    // s.pop();
    // std::cout<<"Last/Top element is: "<<s.top();
    // std::cout<<"Size of stack is: "<<s.size();
    // std::cout<<"Empty or not"<<s.empty();

    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // } 
    // Stack s(5); //object creation where the value inside parenthesis is size.
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // while(!s.empty()){
    //     cout<<s.getTop()<<" ";
    //     s.pop();
    // }

    Stack s(9);
    // s.push1(1);
    // s.push2(2);
    // s.push2(3);
    // s.push2(4);
    // s.push1(5);
    // s.push2(6);
    // s.push1(7 );
    s.push1(20);
    s.push2(-20);
    s.push1(20);
    s.push2(-20);
    s.push1(20);
    s.push2(-20);
    s.push1(20);
    s.push2(-20);
    s.push1(20);
    s.push2(-20);
    s.print();
    s.pop1();
    s.pop2();
        s.pop1();
    s.pop2();

    s.print();
}