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

void convertbst_to_dll(Node* root,Node* &head){
    if(!root) return;
    //r n l
    //r
    convertbst_to_dll(root->right,head);
    root->right = head;
    if(head) //agar dll bana gaya to
        head->left = root;
    head = root;

    convertbst_to_dll(root->left,head);
return ;
}
void printll(Node* head){
    if(!head) return;
    cout<<head->data<<" ";
    if(head->right)
    printll(head->right);
    return;

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
    }
    cout<<endl;
    Node* head = new Node();
    convertbst_to_dll(root,head);
    printll(head);
}




