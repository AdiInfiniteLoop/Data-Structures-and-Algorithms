#include<iostream>
#include<queue>
#include<vector>
using std::cin;
using std::cout;

void fastIO(){
    std::ios::sync_with_stdio(false);
    cin .tie(NULL);
}

struct TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode():data(0),left(NULL),right(NULL){}
        TreeNode(int data):data(data),left(NULL),right(NULL){}
};

TreeNode* buildtree(){
    int data;
    cout<<"Enter the data\n";
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(data);
    cout<<"Left tree->\t";
    root->left = buildtree();
    cout<<"Right tree->\t";
    root->right = buildtree();
    return root;
}

void lefttraversal(TreeNode* root, std::vector<int> &ans){
    if(root == NULL || (root->left == nullptr && root->right == NULL))
        return;
    ans.push_back(root->data);
    if(root->left) lefttraversal(root->left,ans);
    else lefttraversal(root->right,ans);
}

void leaftraversal(TreeNode* root, std::vector<int> &ans){
    if(root == NULL) return;

    if(root->left == nullptr && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    if(root->left)  leaftraversal(root->left,ans);
    if(root->right) leaftraversal(root->right,ans);
}

void righttraversal(TreeNode* root, std::vector<int> &ans){
    if(root == NULL || (root->left == nullptr && root->right == NULL))  return;
    if(root->right) righttraversal(root->right,ans);
    else{
        righttraversal(root->left,ans);
    }
    ans.push_back(root->data);//push_back done after recursive call for reverse insertion
}

std::vector<int> boundarytraversal(TreeNode* &root){
    std::vector<int> res;
    if(root == NULL) return res;
    res.push_back(root->data);
    lefttraversal(root->left,res);

    leaftraversal(root->left,res);
    leaftraversal(root->right,res);
    righttraversal(root->right,res);

    return res;
}

signed main(){
    TreeNode* root = NULL;
    // fastIO();
    root = buildtree();
    // std::vector<int> uttar = boundarytraversal(root);
    for(int &itr: boundarytraversal(root))  cout<<itr<<" ";
}
