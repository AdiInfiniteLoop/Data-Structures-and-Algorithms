#include<iostream>
#include<queue>
using namespace std;

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

void inordertraversal(Node* root){
    if(!root) return ;
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
    return ;
}

Node* insertinBst(Node* root,int data){
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

Node* minimumvalue_in_bst(Node* root){
    Node* temp = root;
    if(!temp) return NULL;
    if(temp->left)
        return minimumvalue_in_bst(temp->left);
    return temp;
}

Node* maximumvalue_in_bst(Node* root){
    Node* temp = root;
    if(!temp) return NULL;
    if(temp->right)
        return maximumvalue_in_bst(temp->right); //don't forget to return as when we make recursive calls but not returning and updating the values 
    return temp;
}
//10 20 5 11 17 2 4 8 6 25 15 -1
signed main(){
    Node* root = NULL;
    cout<<"Enter the data for Node\n";
    root = takeinput(root);

    cout<<"Printing inorder traversal\n";
    inordertraversal(root);
    Node* minvalue = minimumvalue_in_bst(root);
    Node* maxvalue = maximumvalue_in_bst(root);
    cout<<"\nThe minimum value is "<<minvalue->data;
    cout<<"\n The maximum value is "<<maxvalue->data;

}