#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct Node {
Node* links[26];
int sw = 0;
int ew = 0;

bool contains(const char ch) {
  return (links[ch - 'a'] != NULL);
}

void put(const char ch, Node* n) {
  links[ch - 'a'] = n;
}

Node* get(const char ch) {
  return links[ch - 'a'];
}

void incrementStartWith() {
  sw++;
}

void incrementEndsWith() {
  ew++;
}

int getStartsWith() {
  return sw;
}

int getEndsWith() {
  return ew;
}

void decrementStartsWith() {
  sw--;
}

void decrementEndsWith() {
  ew--;
}

};

class Trie {
  private:
    Node* root;
  public:
    Trie() {
      root = new Node();
    }

    void insert(string str) {
      Node* n = root;
      
      for(int i = 0; i < str.length(); ++i) {
        if(!n->contains(str[i])) {
          n->put(str[i], new Node);
        }
        n = n->get(str[i]);
        n->incrementStartWith();
      }
      n->incrementEndsWith();
    }


    int countDistinctNumbers(string str) {
        
        int count = 0;
        for(int i = 0 ; i < str.length(); ++i) {
            Node* n = root;
            for(int j = i; j < str.length(); ++j){
            if(!n->contains(str[i])) {
                n->put(str[i], new Node);
                count++;
            }
            n = n->get(str[i]);                
        }
        }
        return count+1;
    }

};


int main() {
  Trie* t = new Trie();


int count = t->countDistinctNumbers("abcad");

cout<<count;

}
