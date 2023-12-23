#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int data):data(data),left(nullptr),right(nullptr){}
    ~Node(){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* maximum(Node* root){
    Node* temp = root;
    if(!temp) return NULL;
    if(temp->right)
        return maximum(temp->right); //don't forget to return as when we make recursive calls but not returning and updating the values 
    return temp;
}


void inordertraversal(Node* root,vector<int> &ans){
    if(!root) return ;
    inordertraversal(root->left,ans);
    ans.push_back(root->data);
    inordertraversal(root->right,ans);
    return ;
}

Node* insertinBst(Node* root, int data){
    if(!root){
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertinBst(root->left,data);
    }
    else{
        root->right = insertinBst(root->right,data);
    }
    return root;
}

Node* takeinput(Node* root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertinBst(root,data);
        cin>>data;
    }
    return root;
}

Node* deletenodefromBst(Node* root, int data){
    //Base case
    if(!root) return NULL;
    //Find the node we want to delete
    if(root->data == data){
        //Mil gaya
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(root->left && !root->right){
            Node* children_of_leftsubtree = root->left;
            delete root;
            return children_of_leftsubtree;
        }
        if(!root->left && root->right){
            Node* children_of_rightsubtree = root->right;
            delete root;
            return children_of_rightsubtree;
        }
        if(root->right && root->left){
            Node* temp = root->left;
            Node* max_value = maximum(root->left);
            root->data = max_value->data;
            // delete max_value; <- NOT THIS!!!!!!;
            root->left = deletenodefromBst(root->left,max_value->data);
            return root;

        }

    }
    if(data < root->data){
        root->left =  deletenodefromBst(root->left,data);
    }
    if(data > root->data){
        root->right =  deletenodefromBst(root->right,data);
    }
    return root;
}

// 10 20 5 11 17 2 4 8 6 25 15 -1
int main(){

    Node* root = NULL;
    cout<<"Enter the data for the tree\n";
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
    root = deletenodefromBst(root,key);

    inordertraversal(root,ans);
        for(int it: ans){
        cout<< it<<" ";
    }
}   

