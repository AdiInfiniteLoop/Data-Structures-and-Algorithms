    #include<iostream>

struct ListNode {
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

ListNode* removekthnode(ListNode* head,int k){
    int i = 1;
    int N = findLength(head);
    if(k == 0) return head;
    if(k == N){
        ListNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    ListNode* curr = head;
    while(i < N-k){
        curr = curr->next;
        i++;
    }
    ListNode* nextnode = curr->next; 
    curr->next = curr->next->next; 
    nextnode->next = nullptr;

    return head;
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
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth ->next = sixth;
    print(first);
    std::cout<<std::endl; 
    int k = 1;
    ListNode* ans =   removekthnode(first,k);
    print(ans);
    

}