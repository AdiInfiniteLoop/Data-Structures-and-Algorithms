#include <iostream>
#include <vector>
using namespace std;
  

class DisjointSet {
private:
  vector<int> rank, parent, size;
public:
  DisjointSet(int n) {
    rank.resize(n+1, 0); //1-based indexing
    parent.resize(n+1, 0);
    for(int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    size.resize(n+1, 1);
  }

  int findUlp(int node) {
    if(node == parent[node]) return node;
    return parent[node] = findUlp(parent[node]); //parent[node] for Path Compression.
  }

  void UnionByRank(int u, int v) {
    int ulp_u =findUlp(u);
    int ulp_v = findUlp(v);
    if(ulp_u == ulp_v) return;
    if(rank[ulp_u] == rank[ulp_v]) {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
    else if(rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    }
    else {
      parent[ulp_v] = ulp_u;
    }
  }

  void UnionBySize(int u, int v) {
    int ulp_u = findUlp(u);
    int ulp_v = findUlp(v);

    if(ulp_u == ulp_v) return;
    else if(size[ulp_u] < size[ulp_v]) {
      size[ulp_v] += size[ulp_u];
      parent[ulp_u] = ulp_v;
    }//No need for else if as they do the same operation.
    else {
      size[ulp_u] += size[ulp_v];
      parent[ulp_v] = ulp_u;

    }
  }
};


int main (int argc, char *argv[]) {
  
  int n = 7;
  DisjointSet* dis = new DisjointSet(n);
  /* Either use UsionByRank or UnionBySize */



  return 0;
}
