#include<iostream>
#include<stack>
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

Node* reverse(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!st.empty()){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
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
Node* head = new Node(10);
Node* second = new Node(20);
head->next = second;
reverse(head);
printll(head);
}