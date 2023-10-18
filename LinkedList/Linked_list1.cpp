#include<iostream>

class Node{
public:
    int data;
    Node* next;
    Node(){
        this->data;
        this->next;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        this->data = data;
        this->next = next;
    }
};
int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp!= NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void print(Node* first){
    Node* temp = first;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void insertAthead(Node* &head,Node* &tail,int data){
if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
}
Node* newNode = new Node(data);
newNode->next = head;
head = newNode;//newNode ko head banana
}

void insertAttail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertatpos(Node* &head,Node* &tail,int pos, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(pos == 0){
        insertAthead(head,tail,data);
        return;
    }
    int len = findLength(head);
    if(pos == len){
        insertAttail(head,tail,data);
        return;
    }
    int i = 1;
    Node* prev = head;
    while(i < pos - 1){
        prev = prev->next;
        i++;
    }
    Node* newNode = new Node(data);
    Node* curr = prev->next;
    newNode->next = curr;
    prev->next = newNode;
}

void deletion(Node* &head,Node* &tail,int pos){
    //CUD
    if(pos == 1){
        Node* temp = new Node;
        head = head->next;//to point towards nowhere
        temp->next = NULL;
        delete temp;
        return;
    }
    if(pos == findLength(head)){
        Node* temp = new Node;
        tail->next = NULL;
        temp = tail->next;
    }
    int i = 1;
    Node* prev = new Node;
    while(i < pos - 1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
}
int main(){
/*Step1:Dynamic declaration and initialization of list
Step2:Link the lists using->next pointer
Step3:Print it b making temporary node*/
// Node* first = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);
// Node* fourth = new Node(40);
// first->next = second;
// second->next = third;
// third->next = fourth;
// print(first);
// std::cout<<std::endl;
Node* head = new Node(1110); //initialize with avalue to avois 0
Node* tail = new Node(10);
insertAthead(head,tail,110);
insertAthead(head,tail,100);
insertAttail(head,tail,432);

print(head);
std::cout<<"\n";
print(tail);
insertatpos(head,tail,4,2);
std::cout<<"\n";
print(head);
std::cout<<"\n";
deletion(head,tail,1);
print(head);

}