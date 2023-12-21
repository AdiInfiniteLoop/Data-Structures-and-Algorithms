#include<iostream>
#include<queue>
using namespace std;

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

void preordertraversal(Node* root){
    if(root == NULL) return  ;
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void inordertraversal(Node* root){
    if(!root) return ;
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
    return ;
}
void postordertraversal(Node* root){
    if(!root) return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
    return ;
}
Node* insertinBst(Node* root,int data){
    if(!root){ //this is the first node which wil be created
        Node* root = new Node(data);
        return root;
    }

    if(data < root->data ){//If new data is smaller than the root's data then go for left subtree
    root->left = insertinBst(root->left,data);
    }
    else//new data greater than then root data then go for right subtree //ALso handles duplicates case.
    {
        root->right  = insertinBst(root->right,data);
    }
    return root;
}
bool searchinBst(Node*root,int key){
if(!root){
    return false;
    cout<<"Can't find the key\n";
}
if(root->data == key) {
    cout<<"Found the keynode\n";
    return true;
}
if(root->data > key){ //agar key chota to left
    searchinBst(root->left,key);
}
else{
    searchinBst(root->right,key);
}
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

//10 20 5 11 17 2 4 8 6 25 15 -1
signed main(){
    Node* root = NULL;
    cout<<"Enter the data for Node\n";
    root = takeinput(root);
    cout<<"Printing preorder traversal\n";
    preordertraversal(root);
    cout<<"Printing inorder traverasl\n";
    inordertraversal(root);
    cout<<"Printing postordertraversal\n";
    postordertraversal(root);

    cout<<searchinBst(root,25);


}