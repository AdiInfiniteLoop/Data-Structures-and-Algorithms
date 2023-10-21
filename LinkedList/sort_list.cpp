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
    std::cout<<std::endl;
}
  
   ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        ListNode* ans = new ListNode(69);
        ListNode* mptr = ans;
        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr= right;
                right= right->next;
            }
        }
        //left over
        while(left){
            mptr-> next = left;
            mptr = left;
            left = left->next;
        }
        while(right){
            mptr-> next = right;
            mptr = right;
            right = right->next;           
        }

        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
        return ans;
}

    ListNode* middle(ListNode* &head){
    if(head == nullptr) return nullptr;
    else if(head->next == nullptr) return head;
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast && fast->next){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
    ListNode* sortList(ListNode* head) {
        //Base Case
        if(head== nullptr || head->next == nullptr) return head;
        //use merge sort
        ListNode* left = head;
        ListNode* mid = middle(head);
        ListNode* right = mid ->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left,right);
    }


int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(7);
    ListNode* fifth = new ListNode(1);
    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(2);
    ListNode* eighth = new ListNode(2);

first->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = sixth;
sixth->next = seventh;
seventh->next = eighth;

print(first);
sortList(first);
print(first);
}