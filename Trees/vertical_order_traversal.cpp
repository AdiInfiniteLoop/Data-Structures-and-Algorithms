#include<iostream>
#include<queue>
using std::cin;
using std::cout;

void fastIO(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
}
class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode():val(0),left(NULL),right(NULL){}
        TreeNode(int val):val(val),left(NULL),right(NULL){}
};

TreeNode* buildtree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    TreeNode* root = new TreeNode(data);
    cout<<"Left tree\t";
    root->left = buildtree();
    cout<<"Right tree\t";
    root->right = buildtree();
    return root;
}

void levelordertraversal(TreeNode* &root){
    if(root == NULL) return;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<std::endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void verticalordertraversal(TreeNode* & root){

}

signed main(){
    TreeNode* root = NULL;
    root = buildtree();
    
}