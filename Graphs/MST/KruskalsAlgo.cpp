#include<bits/stdc++.h>
using namespace std;
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

int SpanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int,  pair<int, int> > > edges;
    for(int i = 0; i < V; ++i) {
    for(auto it: adj[i]) 
      {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        edges.push_back({wt, {u, v}});
        //No need to insert twice as we are using a DisJoint Set.
      }
    }

    sort(edges.begin(), edges.end());
    int mstWt = 0;
    DisjointSet ds(V);
    for(auto it: edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUlp(u) != ds.findUlp(v)) {
            mstWt += wt;
            ds.UnionBySize(u, v);
        }
    }
    return mstWt;
}

int main(int argc, char *argv[]) {

    int n = 7;
    DisjointSet *dis = new DisjointSet(n);
    /* Either use UnionByRank or UnionBySize */

    //Example usage of the SpanningTree function
    vector<vector<int>> adj[n];
    adj[0].push_back({1, 3, 5}); // edge from node 0 to node 1 with weight 5
    adj[1].push_back({0, 3, 5}); // edge from node 1 to node 0 with weight 5
    int mstWeight = SpanningTree(n, adj);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}
