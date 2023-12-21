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
Node* insertathead(Node* head,int val){
    return new Node(val,nullptr,head);
}
Node* convertfromarr(int *arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i < 7;++i){
        Node * dummy = new Node(arr[i],temp,nullptr);
        temp->next = dummy;
        temp = dummy;
    }
    return head;
}
void printll(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
signed main(){
    Node* head = insertathead(head,2);
    int arr[] = {3,4,5,6,7,8,9};
    head = convertfromarr(arr);
    printll(head);
}