#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode():data(0),prev(nullptr),next(nullptr){}
    ListNode(int data):data(data),prev(nullptr),next(nullptr){}
};

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(nullptr),right(nullptr){}
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
};

void build_ll(ListNode* head){
    int data;
    cin>>data;
    while(data != -1){
        head->data= data;
        head = head->next;
        cin>>data;
    }
}

void printll(ListNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

ListNode* dll_to_bst(ListNode* head,int n){
    if(!head) return NULL;
    // ListNode* leftans = dll_to_bst(head->prev,n/2);

    TreeNode* root = new TreeNode(head->next->data);
    // root->left = head;
    
}

int main(){
    cout<<"Enter the linked list data\n";
    int data;
    cin>>data;
    ListNode* head = new ListNode(data);
    build_ll(head);
    cout<<"The linked list elements are:\n";
    printll(head);
}