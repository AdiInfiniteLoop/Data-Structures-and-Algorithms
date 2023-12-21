#include<iostream>
using namespace std;

class 
Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(): data(0), prev(nullptr),next(nullptr) {}
        Node(int data): data(data),prev(nullptr), next(nullptr) {}
        Node(int data,Node* prev,Node* next): data(data), prev(nullptr), next(nullptr){}

};


Node* convertarrtodll(int arr[]){
    int n = 9;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n;++i){
        Node* dummy = new Node(arr[i],temp,nullptr);
        temp->next = dummy;
        temp = dummy;

    }
    return head;
}
Node* insertathead(Node* head,int val){
    Node* temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    return temp;
}

Node* insertattail(Node* head, int val){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* dummy = new Node(val);
    temp->next = dummy;
    dummy->prev = temp;
    return head;
}
Node* insertbeforetail(Node* head,int val){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* dummy = new Node( val);
    temp->prev->next = dummy;
    dummy->next = temp;
    dummy->prev = temp->prev;
    temp->prev = dummy;
    return head;
}

Node* beforeapos(Node* head, int pos,int val){
    Node* temp = head;
    int i = 1;
    while(i < pos){
        temp = temp->next;
        ++i;
    }
    Node* dummy = new Node(val,temp->prev,temp);
    temp->prev->next = dummy;
     dummy->next = temp;
     return head;
}

void printll(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Node* head = convertarrtodll(arr);
    printll(head);
    head = insertathead(head,-1);
    printll(head);
    head = insertattail(head,10);
    printll(head);
    head = insertbeforetail(head,11);
    printll(head);
    head = beforeapos(head,4,-10);
    printll(head);

}