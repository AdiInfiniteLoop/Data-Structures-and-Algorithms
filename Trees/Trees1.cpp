#include<iostream>
#include<queue>
using  std::cout;
using std::cin;

#define rep(i,a,b) for(int i = a,i < b;i++)
#define vi vector<int>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        this-> left = nullptr;
        this-> right = nullptr;
    }
};

Node* buildTree(){
int data;
cout<<"Enter the data\n";
cin>>data;
if(data == -1) return NULL;
Node* root = new Node(data);
cout<<"Left tree\n";
root->left = buildTree();
cout<<"Right tree\n";
root->right = buildTree();
return root;

}

void LevelOrderTraversal(Node* &root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        
        if(!q.empty())
        q.pop();
    }

}

void InorderTraversal(Node* root){  //LNR Method
    if(root == NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);

}

void PreorderTraversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(Node* root){
    if(root == NULL) return;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    cout<<root->data<<" ";
}
signed main(){
Node* root = nullptr;
root = buildTree();

cout<<"Level Order Traversal\n";
LevelOrderTraversal(root);
cout<<"Inorder traversal\n";
InorderTraversal(root);
cout<<"\nPreorder traversal\n";
PreorderTraversal(root);
cout<<"Postorder traversal\n";
PostorderTraversal(root);

}