#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != NULL){
        std::cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int findLength(ListNode* &head){
    int len = 0;
    ListNode* temp = head;
    while(temp!= NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

ListNode* rotate_list(ListNode* &head,int k){

ListNode* curr = head;
int len = findLength(head);
int i = 1;
while(curr->next && i++) curr = curr->next;
curr->next = head;
k = k % len;
int last_len = len - k;
while(last_len--){
    curr = curr->next;
}
head = curr->next;
curr->next = nullptr;
return head;
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
    
    int k = 2;
 ListNode*ans=   rotate_list(first,k);
    print(ans);

}