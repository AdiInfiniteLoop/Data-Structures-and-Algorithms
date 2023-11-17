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
int maxDepth(Node* &root){
    if(root == NULL){
        return 0;//no height
    }
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int height = std::max(leftHeight,rightHeight)+1;
    return height;
}

bool isbalanced(Node* &root){
if(root == NULL) return true;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int diff = std::abs(leftHeight - rightHeight);
    bool ans = (diff <= 1);
    bool leftans = isbalanced(root->left);
    bool rightans = isbalanced(root->right);
    return ans&& leftans && rightans;

}

signed main(){
    Node* root = nullptr;
    root = buildTree();

}