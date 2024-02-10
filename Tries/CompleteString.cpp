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


bool longestprefix(string str, string &prefix) {
    Node* n = root;
    for (int i = 0; i < str.length(); ++i) {
        if (n->contains(str[i])) {
            prefix += str[i];
            n = n->get(str[i]);
            if (n->getStartsWith() > 1) {
                // More than one child, indicating ambiguity
                break;
            }
     
        }
        else {
          return false;
        } 
    }
    return true;
}

bool completeString(string str) {
  Node* n = root;
  for(int i = 0; i < str.length(); ++i) {
    if(n->contains(str[i])) {
        n = n->get(str[i]);
        if(n->getEndsWith() == 0) return false;
    }
    else {
      return false;
    }
  }
  return true;
}


};


int main() {
  Trie* t = new Trie();

  vector<string> a  = {"abc","abs", "afd"};
  for(string it: a) {
    t->insert(it);
  }
  
  
  string oldstr = "";
  for(string it: a) {
    string newstr = "";
    if(t->longestprefix(it,newstr)) {
      if(newstr.length() > oldstr.length()) {
        oldstr = newstr;
      }
      else if(oldstr.length() == newstr.length() && oldstr < newstr) {
        oldstr = newstr;
      }
    }
  }
  cout<<oldstr;
}
