#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int data):data(data),left(nullptr),right(nullptr){}
    ~Node(){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int inorder_predecessor(Node* root, int node_value) {
    if (!root)
        return -1;

    if (root->data == node_value) {
        cout << "There is no inorder predecessor\n";
        return -1;
    }

    if (root->data > node_value && root->left) {
        if (root->left->data == node_value || root->left->right == nullptr) {
            return root->data;
        } else {
            return inorder_predecessor(root->left, node_value);
        }
    }

    if (root->data < node_value && root->right) {
        if (root->right->data == node_value || root->right->left == nullptr) {
            return root->data;
        } else {
            return inorder_predecessor(root->right, node_value);
        }
    }

    return -1;
}

void inordertraversal(Node* root,vector<int> &ans){
    if(!root) return ;
    inordertraversal(root->left,ans);
    ans.push_back(root->data);
    inordertraversal(root->right,ans);
    return ;
}

Node* insertinBst(Node* root, int data){
    if(!root){
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertinBst(root->left,data);
    }
    else{
        root->right = insertinBst(root->right,data);
    }
    return root;
}

Node* takeinput(Node* root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertinBst(root,data);
        cin>>data;
    }
    return root;
}

// 10 20 5 11 17 2 4 8 6 25 15 -1
int main(){

    Node* root = NULL;
    cout<<"Enter the data for the tree\n";
    root =takeinput(root);

    cout<<"The inorder traversal is: \n";

    inordertraversal(root,ans);
    for(int it: ans){
        cout<< it<<" ";
    }
    cout<<endl;

    cout<<inorder_predecessor(root,10)<<endl;
}