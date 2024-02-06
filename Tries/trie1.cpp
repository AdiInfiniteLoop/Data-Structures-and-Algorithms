#include <iostream>

using namespace std;
struct Node {
  Node* links[26];
  bool flag = false;

  bool contains(char &ch) {
    return (links[ch - 'a'] != NULL);
  }

  void put(char &ch, Node* t) {
    links[ch - 'a'] = t;
    return;
  }

  Node* get(char &ch) {
    return links[ch - 'a'];
  }

  void setEnd() {
    flag = true;
  }

  bool getEnd() {
    return flag;
  }
};

class Trie{
private: 
  Node* root;
public: 
  Trie() {
    root = new Node();
  }

  void insert(string str) {
    Node* n = root;
    for(int i = 0; i < str.size(); ++i) {
      if(!n->contains(str[i])) {
        n->put(str[i], new Node);
      }
      n = n->get(str[i]);
    }
    n->setEnd();
  }

  bool search(string str) {
    Node* n = root;

    for(int i = 0; i < str.size(); ++i) {
      //Check if the trie node exists.
      if(!n->contains(str[i])) {
        return false;
      }
      n = n->get(str[i]);
    }
    return n->getEnd();
  }

  bool startsWith(string str) {
    //Check if the trie node exists.
    Node* n = root;
    for(int i = 0; i < str.size(); ++i) {
      if(!n->contains(str[i])) {
        return false;
      }
      n = n->get(str[i]);
    }
  return true;
  }

};


int main() { 
  Trie t;
  string str1 = "apple";

  t.insert(str1);
  cout<<  t.search("app");
  cout<< t.startsWith("app");

}
