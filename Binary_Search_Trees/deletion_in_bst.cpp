#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> ans;
class TreeNode{
    public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode():key(0),left(nullptr),right(nullptr){}
    TreeNode(int key):key(key),left(nullptr),right(nullptr){}
    ~TreeNode(){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* maximum(TreeNode* root){
    TreeNode* temp = root;
    if(!temp) return NULL;
    if(temp->right)
        return maximum(temp->right); //don't forget to return as when we make recursive calls but not returning and updating the values 
    return temp;
}


void inordertraversal(TreeNode* root,vector<int> &ans){
    if(!root) return ;
    inordertraversal(root->left,ans);
    ans.push_back(root->key);
    inordertraversal(root->right,ans);
    return ;
}

TreeNode* insertinBst(TreeNode* root, int key){
    if(!root){
        root = new TreeNode(key);
        return root;
    }

    if(root->key > key){
        root->left = insertinBst(root->left,key);
    }
    else{
        root->right = insertinBst(root->right,key);
    }
    return root;
}

TreeNode* takeinput(TreeNode* root){
    int key;
    cin>>key;
    while(key != -1){
        root = insertinBst(root,key);
        cin>>key;
    }
    return root;
}

vector<int> levelordertraversal(TreeNode* root){
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        ans.push_back(temp->key);
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;

}
TreeNode* deleteTreeNodefromBst(TreeNode* root, int key){
    //Base case
    if(!root) return NULL;
    //Find the TreeNode we want to delete
    if(root->key == key){
        //Mil gaya
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(root->left && !root->right){
            TreeNode* children_of_leftsubtree = root->left;
            delete root;
            return children_of_leftsubtree;
        }
        if(!root->left && root->right){
            TreeNode* children_of_rightsubtree = root->right;
            delete root;
            return children_of_rightsubtree;
        }
        if(root->right && root->left){
            TreeNode* temp = root->left;
            TreeNode* max_value = maximum(root->left);
            root->key = max_value->key;
            // delete max_value; <- NOT THIS!!!!!!;
            root->left = deleteTreeNodefromBst(root->left,max_value->key);
            return root;

        }

    }
    if(key < root->key){
        root->left =  deleteTreeNodefromBst(root->left,key);
    }
    if(key > root->key){
        root->right =  deleteTreeNodefromBst(root->right,key);
    }
    return root;
}

// 10 20 5 11 17 2 4 8 6 25 15 -1
int main(){

    TreeNode* root = NULL;
    cout<<"Enter the key for the tree\n";
    root =takeinput(root);

    cout<<"The inorder traversal is: \n";

    inordertraversal(root,ans);
    for(int it: ans){
        cout<< it<<" ";
        ans.clear();
    }
    cout<<endl; 
    int key;

    cout<<"Enter the value of key\n";
    cin>>key;
    root = deleteTreeNodefromBst(root,key);

    inordertraversal(root,ans);
    for(int it: ans){
        cout<< it<<" ";
        ans.clear();
    }
    levelordertraversal(root);
    for(int it: ans){
        cout<< it<<" ";
        ans.clear();
    }
    
}   

