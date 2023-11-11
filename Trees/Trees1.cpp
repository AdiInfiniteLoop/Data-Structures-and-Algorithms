#include<iostream>
#include<queue>
using  std::cout;
using std::cin;

#define rep(i,a,b) for(int i = a,i < b;i++)
#define vi vector<int>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        this-> left = nullptr;
        this-> right = nullptr;
    }
};

Node* buildTree(){
    int data;
    cout<<"Enter the data\n";
    cin>>data;
    //Base Case 
    if(data == -1) {
        return NULL;
    }
    //Step A
    Node* root = new Node(data);
    //Step B
    cout<<"Enter data for left part of recent"<<data<<"node:\n";
    root->left= buildTree();
    //Step c
    cout<<"Enter the data for right  part of recent"<<data<<"node:\n";
    root->right = buildTree();
    return root;
}

void LevelOrderTraversal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        //1.Store the front of queue in temp variable
        Node* temp = q.front();
        //2.Pop the front variable
        q.pop();
        //3.Print the answer
        cout<<temp->data<<" ";
        //4.Insert the child nodes in the queue
         if(temp->left) q.push(temp->left);
         if(temp->right) q.push(temp->right);       
    }

}
signed main(){
Node* root = nullptr;
root = buildTree();

LevelOrderTraversal(root);

}