#include<iostream>

struct ListNode{
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
int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(7);
    ListNode* eighth = new ListNode(8);
    ListNode* ninth = new ListNode(9);
    ListNode* tenth = new ListNode(10);


    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    sixth->next =seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;

    print(first);
    print(sixth);
ListNode* uttar = mergeTwoLists(first,sixth);
print(uttar);

    
}