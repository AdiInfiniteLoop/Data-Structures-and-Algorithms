#include<iostream>

class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(){
            this->data;
            this->next;
        }
        ListNode(int data){
            this->data = data;
            this->next = NULL;
        }
        ~ListNode(){
            this->data;
            this->next;
        }
};


void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}

ListNode* detectLoop(ListNode* &head){
     if(head ->next == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL){//use && not ||
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            slow = head;
            break;

    }
}
        ListNode* prev = fast;
        while(fast != slow){
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }

    prev->next = nullptr;
    return slow;
}


int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(7);
    ListNode* eighth = new ListNode(8);

first->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = sixth;
sixth->next = seventh;
seventh->next = eighth;
seventh->next = fourth;

std::cout<<detectLoop(first)->data<<" is the starting point"<<std::endl;
print(first);//after removalof loop
}