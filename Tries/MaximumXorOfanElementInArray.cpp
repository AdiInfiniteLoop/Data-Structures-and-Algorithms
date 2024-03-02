#include<iostream>
#include<vector>
#include<algorithms>
using namespace std;

struct Node {
  Node* links[2] ;
  
  void put(const int num, Node* node) {
    links[num] = node;
  }

  Node* get(int num) {
    return links[num];
  }

  bool contains(const int num) {
    return (links[num] != NULL);
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
          n->put(bit);
        }

        n = n->get(bit);
      }
    }
    int getMax(int num) {
      Node* n = root;
      int maxi = 0;
      for(int i = 31; i >= 0; --i) {
        int bit = (num >> i) &1;
        if(n->contains(!bit)) {
          maxi = maxi | (1<<i);
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
  std::vector<int> nums = {0, 1, 2, 3, 4};
  std::vector<vector<int> > queries {{3, 1}, {1, 3}, {5, 6}};
  sort(nums.begin(), nums.end());
  
  //Storing the queries wrt A[i] and with query number.
  vector< pair<int, pair<int, int> > > oq; //oq means Offline Queries here.
  int n = queries.size();
  for(int i = 0; i < n; ++i) {
    oq.push_back({queries[i][1], {queries[i][0], i}});
  }
  vector<int> ans;
  sort(oq.begin(), oq.end());
  Trie t;
  int ind = -1;
  for(int i = 0; i < n; ++i) {
    int xi = oq[i].second.first;
    int qno =  oq[i].second.second;
    int ai = oq[i].first;
    
    while(ind < arr.size() && arr[i] <= ai) {
      t.insert(arr[i]);
      ind ++;
    }
    int ele = t.getMax(xi); //have to find xor for xi;
    ans.push_back(ele);
    

  }
  
}
