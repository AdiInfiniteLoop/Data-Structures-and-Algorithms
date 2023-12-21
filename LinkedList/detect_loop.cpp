#include<iostream>
class ListNode{
    public:
        int data;
        ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = nullptr;
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
    std::cout<<std::endl;
}
ListNode* detect_loop(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast && slow != fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return head;
}   

int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5); 
    ListNode* sixth = new ListNode(6);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;
    print(first);

    ListNode* headofloop = detect_loop(first);
    std::cout<<headofloop->data;




}