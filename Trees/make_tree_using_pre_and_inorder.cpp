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
    std::queue<TreeNode*>q;
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
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
void preorder(TreeNode* &root){
    if(root == NULL){
        return;
    }
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* &root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    cout<<root->val;
    preorder(root->right);
}

int find(int arr[], int ele,int n){
    for(int i = 0; i < n - 1;i++){
        if(ele == arr[i]) return i;
    }
    return -1;
}

TreeNode* buildfrompreorderinorder(int inorder[] , int preorder[],int size ,int &index, int inorderstart, int inorderend){
//base case
//by reference index: once  a element is traversed then move forward
if(index >= size || inorderstart > inorderend){
    return NULL;
}
//step.1
int rootelement = preorder[index++];
TreeNode* root = new TreeNode(rootelement);
int pos = find(inorder,rootelement,size);
//step.2
root->left = buildfrompreorderinorder(inorder,preorder,size,index, inorderstart ,pos-1);
root->right = buildfrompreorderinorder(inorder,preorder,size,index,pos+1,inorderend);
return root;

}

TreeNode* buildfrompostorderinorder(int inorder[] , int postorder[],int size ,int &postindex, int inorderstart, int inorderend){
    if(postindex < 0 || inorderstart > inorderend){
    return NULL;
}
//step.1
int rootelement = postorder[postindex--];
TreeNode* root = new TreeNode(rootelement);
int pos = find(inorder,rootelement,size);
//step.2
root->right = buildfrompreorderinorder(inorder,postorder,size,postindex,pos+1,inorderend);
root->left = buildfrompreorderinorder(inorder,postorder,size,postindex, inorderstart ,pos-1);

return root;
}

signed main(){
    // TreeNode* root = NULL;
    // root = buildtree();
    // levelordertraversal(root);
    int size = 11;
    int* inorder = new int[size] {4,3,5,2,6,1,9,8,10,7,11};
    int* preorder = new int[size] {1,2,3,4,5,6,7,8,9,10,11};
    int inorderstart = 0;
    cout<<"PreOrder Traversal\n";
    TreeNode* newroot = buildfrompreorderinorder(inorder,preorder,size,inorderstart,0,size-1);
    levelordertraversal(newroot);
    int* postorder = new int[size]{4,5,3,6,2,9,10,8,11,7,10};
    cout<<"PostOrder Traversal:\n";
    TreeNode* newernode = buildfrompostorderinorder(inorder,postorder,size,inorderstart,0,size - 1);
    levelordertraversal(newernode);
}