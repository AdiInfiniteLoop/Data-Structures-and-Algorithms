#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void removeduplicates(ListNode* &head){
    ListNode* temp = head;
    while(temp != nullptr && temp ->next != nullptr){
        if(temp->val == temp->next->val){
            temp->next = temp->next->next;
            // temp->next = nullptr; don't do nullptr as it won't printful list
        }
        temp = temp->next;
    }

    // return temp;//the duplicate element
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != NULL){
        std::cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(3);
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

removeduplicates(first);
print(first);

}