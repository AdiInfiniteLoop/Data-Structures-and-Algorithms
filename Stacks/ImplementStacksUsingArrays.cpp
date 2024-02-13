#include<iostream>

using namespace std;

class Stack {
private: 
  int capacity;
public:
  Stack(int capacity) {
    this->capacity = capacity;
  }
private:
  int* stack = new int(capacity);
  int top = -1;
public:

  void push(const int data) {
    if(top == capacity) {
      cout<<"Not possible\n";
      return;
    }
    stack[++top] = data;
  }

  int pop() {
    if(top == -1) {
      cout<<"Not possible: Underflow";
      return -1;
    }
     int topele = stack[top];
     top--;
     return topele;
  }

  int getTop() {
    return stack[top];
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == capacity;
  }
};


int main() {
  Stack* st = new Stack(5);

}
