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
    cout<<"Enter the data\t";
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(data);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

std::vector<int> zigzagtraversal(TreeNode* &root){
    // vector<int> ans;
    std::vector<int> res;
    if(root == NULL)return res;
    std::queue<TreeNode*> q;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
        std::vector<int> ans;
        int size = q.size();
        for(int i = 0; i < size; ++ i){
        TreeNode* front = q.front();
        q.pop();
        int index;
        if(lefttoright){    //left to right jana hain
            index = i;
        }
        else{
            index = size - i;
        }
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
        ans[index] = (front->data);

        }
        lefttoright = !lefttoright;
        for(auto &itr: ans)
        res.push_back(itr);
    }
    return res;
}

signed main(){
    TreeNode* root = NULL;
    root = buildtree();
    zigzagtraversal(root);
}