#include<iostream>
#include<queue>
using std::cout;
using std::cin;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
        ~Node(){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
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

int diameterOfBinaryTree(Node* &root){
        if(root == NULL) return 0;
        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = std::max(opt1,std::max(opt2,opt3));
        return ans;
}

signed main(){
    Node* root = nullptr;
    root = buildTree();
    levelordertraversal(root);



}