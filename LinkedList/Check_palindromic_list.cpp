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
ListNode* middle(ListNode* &head){
    if(head == nullptr) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    if(head ->next == nullptr) return head;
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
bool isPalindrome(ListNode* &head){
    if(head == nullptr){
        return true;
    }
    if(head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next;
        if(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
        }
    } 
    //slow is middle 
    ListNode* reversed = reverse(slow->next);
    slow->next =reversed;//joining not necessary
    ListNode* temp = head;
    ListNode* temp1 = reversed;
    while(temp != nullptr && temp1 != nullptr){
        if(temp->data != temp1->data) return false;
        temp = temp->next;
        temp1 = temp1->next;
    }
    return true;
}
int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    // ListNode* third = new ListNode(3);
    // ListNode* fourth = new ListNode(3);
    // ListNode* fifth = new ListNode(2);
    // ListNode* sixth = new ListNode(1);
    first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    print(first);
    std::cout<<middle(first)->data<<" is the middle node\n";
    std::cout<<isPalindrome(first);


}