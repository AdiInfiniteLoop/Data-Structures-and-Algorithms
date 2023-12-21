#include <iostream>

using namespace std;

class
 
Node {

    public:
        int data;
        Node* next;

        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data) , next(nullptr) {}
        Node(int data, Node* next) : data(data), next(next) {}
};

void printll(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head  = head->next;
    }
    cout<<endl;
}
Node* convertarrt0ll(int *arr){
    Node* first = new Node(arr[0]);
    Node* dummy  = first;
    for(int i = 1; i < 9;++i){
        Node* temp = new Node(arr[i]);
        dummy->next = temp;
        dummy = temp;
    }
    return first;
}
Node* deletefromhead(Node* head){
    if(head == NULL) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp; // Use delete instead of free for dynamically allocated objects
    return head;
}
Node* deletefromtail(Node* head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
     temp->next = NULL; //making it null works rather than deleting it as it causes segmentation fault.
    return head;
}
Node* delfromposition(Node* head,int pos){
    if(head == NULL){
        cout<<"Deletion not possible\t";
        return NULL;
    }
    if(head == NULL && pos > 1){
        cout<<"Deletion not possible\t";
        return NULL;
    }
    else{
        Node* temp = head;
        int i = 1;
        while(i < pos -1){
            temp = temp ->next;
            ++i;
        }
        temp->next = temp->next->next;

        return head;
    }
}
Node* delafterpos(Node* head,int pos){ //or take pos % size of linked list to avoid pos being greater than the size of ll.
        if(head == NULL){
        cout<<"Deletion not possible\t";
        return NULL;
    }
    if(head == NULL && pos > 1){
        cout<<"Deletion not possible\t";
        return NULL;
    }
    else{
        Node* temp = head;
        int i = 1;
        while(i < pos ){
            temp = temp ->next;
            ++i;
        }
        temp->next = temp->next->next;

        return head;
    }
}

Node* delbeforeposition(Node* head, int pos) {
    if (head == NULL) {
        cout << "Deletion not possible\t";
        return NULL;
    }

    // Handle the edge case where pos == 2
    if (pos == 2 && head->next != NULL) {
        return deletefromhead(head);
    }

    // Handle edge cases
    if (pos < 1 || head->next == NULL) {
        cout << "Deletion not possible\t";
        return head;
    } else {
        Node* temp = head;
        int i = 1;
        while (i < pos - 2) {
            temp = temp->next;
            ++i;
        }
        if (temp->next != NULL) {
            temp->next = temp->next->next;
        } else {
            cout << "Deletion not possible\t";
        }

        return head;
    }
}
Node* delvalue(Node* head, int value){
    Node* temp = head;
    while(temp->next->data != value){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
signed main(){
    int arr[] = {5,3,5,6,7,4,9,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = convertarrt0ll(arr);
    head = deletefromhead(head); //don't forget to update head pointer after deletion so that we won't lose it.
    printll(head);
    head = deletefromtail(head);
    printll(head);
    head = delbeforeposition(head,2);
    head = delvalue(head,6);
    printll(head);
}