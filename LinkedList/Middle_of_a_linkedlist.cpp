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
            this->data;
            this->next;
        }
};
void insertathead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail= newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* middle(Node* &head){
    Node* temp = head;
    if(head == NULL)
    if(head->next == NULL) return head;
    Node* fast = head;
    Node* slow = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
int main(){
    Node* head = new Node(5);
    Node* tail = NULL;
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    insertathead(head,tail,1);
        insertathead(head,tail,1);
    print(head);
    std::cout<<std::endl;
    std::cout<<"Middle node is: "<<middle(head)->data;
    
}