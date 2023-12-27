#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data):data(data),left(nullptr),right(nullptr){}
};