#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node():data(0), left(nullptr),right(nullptr) {}
        Node(int data):data(0) , left(nullptr),right(nullptr) {}
};


Node* buildTree(){
    int data;
    cout<<"Enter the data\n";
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    Node* root = new Node(data);
    cout<<"Left tree->\t";
    root->left = buildTree();
    cout<<"Right tree->\t";
    root->right = buildTree();
    return root;
}

void levelordertraversal(Node* &root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        if(!q.empty()){
            q.pop();
        }
        if(temp==NULL){
            cout<<std::endl;
            if(!q.empty())q.push(NULL);
        }
        else{
        cout<<temp->data<<" ";

        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        }
    }

}
bool isSamehelper(Node* leftnode,Node* rightnode){
    if(leftnode == NULL || rightnode == NULL) return leftnode == rightnode;
    if(leftnode->data != rightnode->data) return false;
    return isSamehelper(leftnode->left,rightnode->right) && isSamehelper(leftnode->right,rightnode->left);
}

bool isSame(Node* root){
    
        return root == NULL || isSamehelper(root->left,root->right);
    }

signed main(){
    Node* root = nullptr;
    root = buildTree();
    cout<< isSame(root);
}