#include<iostream>
using namespace std;
class Node{
public:
    int x;
    Node* next;
    Node(){
        this-> x = 0;
        this->next = NULL;
    }
    Node(int x){
        this->x = x;
        this->next = NULL;
     }
};
void printLL(Node* n1){
    Node* itr = n1;
    while(itr != NULL){
        std::cout<<itr->x<<" ";
        itr = itr->next;
    }
}

int main(){
//dynamic initalization of linked list
Node* first = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);

//Linking the list
first-> next = second;
second-> next = third;
third-> next = fourth;

cout<<"Printinglinked lists:\t";//don't forget to call the function
printLL(first);
}