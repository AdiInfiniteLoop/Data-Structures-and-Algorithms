
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector<int>
#define si set<int>
#define mp map<int, int>
#define ump unordered_map<int, int>
#define tn Trie
#define n Node

struct n {
    n* children[26];
    bool flag = false;

    bool contains(char ch) {
        return !(children[ch - 'a'] == NULL);
    }
    void putChar(char ch, n* node){
        children[ch - 'a'] = node;
    }

    n* get(char ch){
        return (children[ch - 'a']);
    }
    void setEnd(){
        flag = true;
    }

    bool getEnd(){
        return flag;
    }

};

class tn {
private:
    n* root;
public:
    tn() {
        root = new n();
    }

    void insert(string str) {
        n* node = root;
        for(int i = 0; i < str.length(); ++i) {
            if(!(node->contains(str[i]))) {
                node->putChar(str[i], new n());
            }
            node = node->get(str[i]);             
        }
        node->setEnd();  
    }

    bool search(string str) {
        n* node = root;
        for(int i = 0; i < str.length(); ++i) {
            if(!node->contains(str[i])){
                return false;
            }
            node = node->get(str[i]);
        }
        return node->getEnd();
    }

    bool startsWith(string str) {
        n* node = root;
        for(int i = 0; i < str.length(); ++i) {
            if(!node->contains(str[i])){
                return false;
            }
            node = node->get(str[i]);

        }
        return true;
    }
};

int main() {
    tn* root = new tn();
    root->insert("inserting");
    cout<<root->search("inserting");
    cout<<root->startsWith("i");
  return 0;
}

