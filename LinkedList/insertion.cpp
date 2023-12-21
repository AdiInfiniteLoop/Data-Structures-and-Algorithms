#include<iostream>
using namespace std;
class
Node{
    public:
        int data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data) , next(nullptr) {}
        Node(int data, Node* next) : data(data) , next(next) {}
};

void printll(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
Node* insertathead(Node* head, int val){
    return new Node(val,head);

}
Node* insertattail(Node* head,int val){
    Node* temp = head;
    if(head == NULL){
        insertathead(head,val);
    }
    Node * dummy = new Node(val,nullptr);
    while(temp->next){
        temp = temp->next;
    }temp ->next  = dummy;
    return head;
}
Node* insertatpos(Node* head,int val,int pos){
    Node* temp = head;
    if(head == NULL && pos > 1){
        cout<<"Insertion not possiblr\n";
        return NULL;
    }
    else if(head == NULL && pos == 1){
        insertathead(head,val);
        return head;
    }
    else{
        int i = 1;
        while(i < pos -1 && temp->next){ //temp->next for edge cases for the last node.
            temp = temp->next;
            ++i;
        }
    Node* dummy = new Node(val,temp->next->next);
        temp->next = dummy;
    }
    return head;
}
signed main(){
    Node* head = new Node(10);
    int val;
    cout<<"Enter the value to be inserted\n";
    cin>>val;
    head = insertathead(head,val);
    head =insertattail(head,20);
    head = insertatpos(head,100,2);
    printll(head);
}