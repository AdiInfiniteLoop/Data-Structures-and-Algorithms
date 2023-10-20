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
int countZeros(ListNode* &head){
    int countZeroes = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->val == 0) countZeroes++;
        temp = temp->next;
    }
    return countZeroes;
}

int countFirst(ListNode* &head){
    int countFirst = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->val == 1) countFirst++;
        temp = temp->next;
    }
    return countFirst;
}

int countsTwo(ListNode* &head){
    int countTwo = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->val == 2) countTwo++;
        temp = temp->next;
    }
    return countTwo;
}

void sorting(ListNode* &head,int c0,int c1,int c2){
int i = 0;
ListNode* temp = head;
while(i < c0){
    temp->val = 0;
    temp = temp->next;
    i++;
}
i = c0;
while(i < c0 + c1){
    temp->val = 1;
    temp = temp->next;
    i++;
}
i = c0+c1;;
while(i < c0+c1+c2){
    temp->val = 2;
    temp = temp->next;
    i++;
}
}
int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(0);
    ListNode* fifth = new ListNode(1);
    ListNode* sixth = new ListNode(1);
    ListNode* seventh = new ListNode(2);
    ListNode* eighth = new ListNode(2);

first->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;
fifth->next = sixth;
sixth->next = seventh;
seventh->next = eighth;
int c0 = countZeros(first);
int c1= countFirst(first);
int c2=countsTwo(first);

sorting(first,c0,c1,c2);
print(first);
}