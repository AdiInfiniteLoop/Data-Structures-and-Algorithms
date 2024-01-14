#include<iostream>
using namespace std;
#include<limits.h>
#define T int
 class Node {
    public:
    int data;
        Node*left;
        Node*right;
        
        Node(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~Node() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

int ans = INT_MAX;
int findCeil(Node *node, int x){
    if(node == NULL) return -1;
    if(x == node->data) return x;
    if(x > node->data && node->right){
        return findCeil(node->right, x);
    }
    else if(x < node->data){
        int ans = min(ans,node->data);
    }
    return ans;

}