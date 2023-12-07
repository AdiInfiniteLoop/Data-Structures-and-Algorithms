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
  
ListNode* convertarrt0ll(int *arr){
    ListNode* first = new ListNode(arr[0]);
    ListNode* dummy  = first;
    for(int i = 0; i < 7;++i){
        ListNode* temp = new ListNode(arr[i]);
        dummy->next = temp;
        dummy = temp;
    }
    return first;
}
int main(){
    int arr[] = {2,4,5,7,9,0,04};

convertarrt0ll(arr);

ListNode* head  = convertarrt0ll(arr);
print(head);
}