#include<iostream>
class ListNode{
    public:
        int data;
        ListNode* next;
    ListNode(int data){
        this->data = data;
        this->next = nullptr;
    }
};
int findLength(ListNode* &head){
    int len = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        len+=1;
    }
    return len;
}

ListNode* reverseknodes(ListNode* &head,int k){
    if(head == nullptr){
        return NULL;
    }
    int len = findLength(head);
    if(k > len){
        return head;
    }
    if(k == len){
        ListNode *prev = NULL;
        while(head != NULL){
            ListNode *nextNode = head->next; 
            head->next = prev;
            prev = head; 
            head = nextNode;     
        }
        return prev;//prev is new updated head
    }
    int count = 0;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = curr->next;
    while(count < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    if(nextNode == NULL) return NULL;
    else head->next = reverseknodes(nextNode,k);
    return prev;
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    ListNode* head = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* fourth = new ListNode(40);
    ListNode* fifth = new ListNode(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // print(head);
    head = reverseknodes(head,5);
    print(head);

}