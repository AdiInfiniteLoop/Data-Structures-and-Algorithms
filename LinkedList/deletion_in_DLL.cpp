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



Node* deleteformhead(Node* head){
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}


Node* deletefromtail(Node* head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}


Node* deletefrompos(Node* head,int pos){
    Node* temp = head;
    if(head == NULL){
        cout<<"Deletion not possible\t";
        return head;
    }
    if(pos == 1 && head ->next){
        deleteformhead(head);
        return head;
    }
    else{
        int i = 1;
        while(i < pos - 1){
            temp = temp->next;
            ++i;
        }
        temp->next = temp->next->next;  //check for some other way where allocated memory can be deleted.
    }
    return head;
}


Node* deletekthnode(Node* head, int val) {
  Node* temp = head;
  while (temp && temp->data != val) {
    temp = temp->next;
  }
Node* back =temp->prev;
Node* front = temp->next;
  if (temp == nullptr) {
    // Node not found
    return head;
  }


  // Handle head deletion
  if (temp == head) {
    head = head->next;
  }
    // Update previous and next pointers
  if (back) {
    back->next = front;
  }
  if (front) {
    front->prev = back;
  }

    delete temp;

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
    head = deleteformhead(head);
    printll(head);
    head = deletefromtail(head);
    printll(head);
    head = deletefrompos(head,3);
    printll(head);
    head = deletekthnode(head,7);
    printll(head);
}