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

struct Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node():data(0),left(NULL),right(NULL){}
        Node(int data):data(data),left(NULL),right(NULL){}
};

Node* buildtree(){
    int data;
    cin>>data;
    if(data == -1) {
        return NULL;
    }
    Node* root = new Node(data);
    std::cout<<"Enter the data for left tree\t";
    root->left = buildtree();
    std::cout<<"Enter the data for right tree\t";
    root->right = buildtree();
    return root;
}

std::vector<int> topview(Node* &root){
    std::queue<std::pair<Node*,int>>q;
    std::map<int,Node*> mp;
    std::vector<int>v;
    q.push(std::make_pair(root,0));
    while(!q.empty()){
        std::pair<Node*,int> temp_pair = q.front();
        q.pop();
        Node* temp =temp_pair.first;
        int lvl = temp_pair.second;
        if(mp.find(lvl) == mp.end()){
            mp[lvl] = temp;
        }
        //Push children
        if(temp->left)q.push(std::make_pair(temp->left,lvl-1));
        if(temp->right)q.push(std::make_pair(temp->right,lvl+1));
    }
    for(auto &it: mp){
        v.push_back(it.second->data);
    }
    return v;
}
signed main(){
    Node* root = NULL;
    root = buildtree();
    for(int it:topview(root))cout<<it<<" ";
}