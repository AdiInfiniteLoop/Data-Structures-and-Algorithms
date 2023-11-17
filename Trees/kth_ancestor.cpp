#include<iostream>
#include<queue>
using std::cout;
using std::cin;
void fastIO(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
}

class TreeNode{
    public:
        int val;
        TreeNode*left;
        TreeNode* right;
        TreeNode():val(0),left(NULL),right(NULL){}
        TreeNode(int val):val(val),left(NULL),right(NULL){}
};

TreeNode* buildtree(){
    //Base Case
    int val;
    cin>>val;
    if(val == -1) return NULL;
    TreeNode* root = new TreeNode(val);
    cout<<"Value for left tree ";
    root->left = buildtree();
    cout<<"Value for right tree ";
    root->right = buildtree();
    return root;
}

void levelordertraversal(TreeNode* &root){
    //Base Case
    if(root == NULL) return;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<std::endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        }
    }
}
bool Kth_ancestor(TreeNode* root,int k,int p){
    if(root == NULL) return false;
    if(root->val == p) return true; 
    
    bool leftans = Kth_ancestor(root->left,k,p);
    bool rightans = Kth_ancestor(root->right,k,p);
    if(leftans || rightans) k--;
    if(k == 0){ cout<<root->val<<" ";
        k = -1;
    }
    return leftans||rightans;

}
//     1
//    / \
//   2   3
//  / \
// 4   5

signed main(){
TreeNode* root = NULL;
root = buildtree();
levelordertraversal(root);

Kth_ancestor(root,1,3);
}