#include<iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int findLength(ListNode* &head){
    int len = 0;
    if(head == nullptr) return 0;
    if(head->next == nullptr) return 1;
    ListNode* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        len++;
    }
    return len;
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != NULL){
        std::cout<<temp->val<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while(a && b){
        if( a == b ) return a;
        a = a->next;
        b = b->next;
    }
    if(a == nullptr && b == nullptr &&a != b)
    return nullptr;

    if(a == nullptr){
        int blen = 0;
        while(b){
            blen++;
            b = b->next;
        }
        while(blen != 0){
            headB = headB ->next;
            blen--;
        }
    }
    else{
        int alen = 0;
        while(a){
            alen++;
            a = a->next;
        }
        while(alen){
            headA = headA ->next;
            alen--;
        }
    }

    while(headA != headB){
    headA = headA ->next;
    headB = headB ->next;
    } return headA;
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
    fifth->next = eighth;

    sixth->next =seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    
    // print(first);
    // print(sixth);
    // int diff  = abs(findLength(first) - findLength(sixth));
    ListNode* ans = getIntersectionNode(first,sixth);
    std::cout<<ans->val<<" is the intersection node\n";

}