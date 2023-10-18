#include<iostream>
//Doubly Linked List
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data;
        this->prev = next;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        this->data = data;
        this->prev = next;
        this->next = NULL;

    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int findLength(Node* &head){
    int len  = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertathead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertattail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode; 
}
void insertatpos(Node* &head,Node* &tail,int pos,int data){
        if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(pos == 1) {
        insertathead(head,tail,data);
        return;
    }
    int len = findLength(head);
    if(pos == len){
        insertattail(head,tail,data);
        return;
    }
    Node* newNode  = new Node(data);
    int i =1;
    Node* prev = head;
    while(i < pos -1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    newNode->next = curr;
    prev->next = newNode;
    curr->prev = newNode;
    newNode->prev = prev;



}
int main(){
Node* first = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);

//Linking the Nodes
first->next = second;
second->next = third;
third->next = fourth;

fourth->prev = third;
third->prev = second;
second->prev = first;
print(first);
std::cout<<"\n";
std::cout<<findLength(first)<<" is the size of Linked List\n";
Node* head = new Node(1);
Node* tail = new Node(2);
head->next = tail;
insertathead(head,tail,100);
print(head);
insertattail(head,tail,99);
print(tail);
std::cout<<std::endl;
insertatpos(head,tail,0,98);
print(head);
}