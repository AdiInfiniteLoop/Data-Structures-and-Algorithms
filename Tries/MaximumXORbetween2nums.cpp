#include<iostream>
#include<string>
using namespace std;

struct Node {
  Node* links[2];
  bool flag = false;

  bool contains(int bit) {
    return (links[bit] != NULL);
  }

  void put(int bit,Node* node) {
    links[bit] = node;
  }

  Node* get(int bit) {
    return links[bit];
  }
  
  void setEnd() {
    flag = true;
  }

  bool getEnd() {
    return flag;
  }

};

class Trie {
  private:
    Node* root;
  public:
    Trie() {
      root = new Node();
    }
    
    void insert(int num) {
      Node* n = root;
      for(int i = 31; i >= 0; --i) {
        int bit = (num>>i) & 1;
        if(!n->contains(bit)) {
          n->put(bit, new Node());
        }
        n = n->get(bit);
      }
    }

    int getMax(int num) {
      Node* n = root;
      int maxi = 0; 
      for(int i = 31; i >= 0; --i) {
        int bit = (num>>i) &1;
        if(n->contains(!bit)) {
          maxi = maxi | (1 << i);
          n = n->get(!bit);
        }
        else if(n->get(bit) != NULL) {
          n = n->get(bit);
        }
      }
      return maxi;
    }


};



int main() {
  Trie* t = new Trie();
  t->insert(3);
  t->insert(3);
  cout<<t->getMax(3);
}
