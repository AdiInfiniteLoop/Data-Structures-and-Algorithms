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
void insertAtTail(Node* &head,Node* &tail,int data){
   
    if(head == NULL){
    Node* newNode = new Node(data);//create new node
    head = newNode;
    tail = newNode;
    return;
}
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;

}
void insertAtHead(Node* &head,Node* &tail,int data){    //pass head by reference 

    if(head == NULL){
    Node* newNode = new Node(data);//create new node
    head = newNode;
    tail = newNode;
    return;
}
    Node* newNode = new Node(data);
    newNode->next = head;

    head = newNode;
}

void insertAtPos(int pos, Node* &head, Node* &tail,int data){
    if(head == NULL){
    Node* newNode = new Node(data);//create new node
    head = newNode;
    tail = newNode;
    return;
}
    //Step.1 find the position this->position = pos samjhe

    int i = 1;
    Node* prev = head;//make prev as new head since during printing only 3 elements will be printed
    while(i < pos){
        prev = prev->next;//move prev ahead so keep updating prev with its next node
        i++;
    }
    Node* curr = prev->next;
    //step.2 create a new node to be inserted
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}
int main(){
//dynamic initalization of linked list
// Node* first = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);

// //Linking the list
// first-> next = second;
// second-> next = third;
// third-> next = fourth;

// cout<<"Printinglinked lists:\t";//don't forget to call the function
// printLL(first);

//insert node at head
// Node* head = new Node(); LEADS TO PRINTING A 0 AT THE END
Node* head = NULL; //TO ENSURE THAT THE LIST IS EMPTY
Node* tail = NULL;
insertAtHead(head,tail,5);
insertAtHead(head,tail,10);
insertAtHead(head,tail,15);
insertAtHead(head,tail,20);
insertAtHead(head,tail,25);
// printLL(head);
insertAtTail(head,tail,30);
// printLL(tail);

insertAtPos(0,head,tail,11);
printLL(head);
cout<<head->x<<" ";
cout<<tail->x;
}
