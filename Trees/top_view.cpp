#include<iostream>
#include<map>
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

std::vector<int> topview(TreeNode* &root){
    std::map<int,int> map;
    std::vector<int> ans;
    std::queue<std::pair<TreeNode*,int>>q;
    q.push(std::make_pair(root,0));
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* curr = it.first;
        int line = it.second;
        if(map.find(line) == map.end()) map[line] = curr->data;
        if(curr->left) q.push(std::make_pair(curr->left,line-1));
        if(curr->right) q.push(std::make_pair(curr->right,line+1)); 
    }
    for(auto it:map)ans.push_back(it.second);
    return ans;

}
signed main(){
    TreeNode* root = NULL;
    root = buildtree();
    for(int it:topview(root))cout<<it<<" ";
}