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
ListNode* reverse(ListNode* &head){
    if(head == nullptr) return nullptr;
    else if(head->next == nullptr) return head;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode = curr->next;
    while(curr != nullptr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

ListNode* addNumbers(ListNode* &l1,ListNode* &l2){
    //reverse
    ListNode* head1 = reverse(l1);
    ListNode* head2 = reverse(l2);
    //add the linked lists
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;

    ListNode* anshead = nullptr;
    ListNode* anstail = nullptr;
    int carry;

    while(temp1 != nullptr && temp2 != nullptr){
        int sum = carry + temp1->val + temp2->val;
        int digit = sum%10;
        carry = sum/10;//avoid redeclaration
        
        ListNode* newNode = new ListNode(digit);

        if(anshead == nullptr){
            anshead = newNode;
            anstail = newNode;
        }
        else{
            anstail -> next = newNode;
            anstail = newNode;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1 != nullptr){
        int sum = carry + temp1->val;
        int digit = sum%10;
        carry = sum/10;
        ListNode* newNode = new ListNode(digit);
        anstail->next = newNode;
        anstail = newNode;
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        int sum = carry + temp2->val;
        int digit = sum%10;
        carry = sum/10;
        ListNode* newNode = new ListNode(digit);
        anstail->next = newNode;
        anstail = newNode;
        temp2 = temp2->next;
        
    }
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        ListNode* newNode = new ListNode(digit);
        anstail->next = newNode;
        anstail = newNode;
    }
    return reverse(anshead);
}
int main(){
    ListNode* first1 = new ListNode(2);
    ListNode* second1 = new ListNode(4);
    ListNode* third1 = new ListNode(3);

    ListNode* first2 = new ListNode(6);
    ListNode* second2 = new ListNode(6);
    ListNode* third2 = new ListNode(4);

    first1->next = second1;
    second1->next = third1;
 

    first2->next = second2;
    second2->next = third2;

ListNode* uttar =  addNumbers(first1,first2);
print(uttar);
}