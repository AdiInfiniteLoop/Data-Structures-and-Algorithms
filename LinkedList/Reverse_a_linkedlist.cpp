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

Node* reverselist(Node* head) {
    Node *prev = NULL;
    while(head != NULL){
        Node *nextNode = head->next; 
        head->next = prev;
        prev = head; 
        head = nextNode;
    }
    return prev;
}

Node* deleteDuplicates(Node* head) {
    Node* temp = head;
    Node* nextnode;
    while(temp && temp->next){
        nextnode = temp->next;
        if(temp->data == nextnode->data){
            temp->next = temp->next->next;
            nextnode->next = nullptr;
            free(nextnode);
            //remove the next node
        }
        temp = temp->next;
    }
    return head;
}
// CHECK THE  CODE OUTPUT NOT SHOWING
// Node* reverselist(Node* & prev,Node* & curr){
//     if(curr== NULL) return prev;
//     Node* nextNode = curr->next;
//     curr->next = prev;
//     return reverselist(prev,nextNode);

// }


int main(){
    Node* head = new Node(5);
    Node* tail = NULL;
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,1);
    insertathead(head,tail,1);
    insertathead(head,tail,1);
    insertathead(head,tail,1);
    print(head);
    Node* curr = head;
    head = reverselist(curr);   
    std::cout<<std::endl;
    print(head);
    std::cout<<std::endl;
    deleteDuplicates(head);
    print(head);
}