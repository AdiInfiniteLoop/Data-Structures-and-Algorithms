#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<stack>
#include<algorithms>

using namespace std;

void toposort(vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st, int node) {
  vis[node] = 1;

  for(auto temp = adj[node]) {
    if(!vis[temp.first]) {
      toposort(adj, vid, st, temp.first);
    }
  }
  st.push(node);
}
vector<int> shortestPath(vector<vector<int>> &edges, int n int m) {
//n means number of nodes and m means number of edges.

//1.Creation of adjacency list.
vector<vector<pair<int, int>>> adj(N);
for(int i = 0; i < m; ++i) {
  int u = edges[i][0];
  int v = edges[i][1];
  int wt = edges[i][2];
  adj[u].push_back({v, wt});
}

//TopoSort
stack<int> st;
vector<int> vis(n, 0);

for(int i = 0; i < n; ++i ) {
  if(!vis[i]) {
    toposort(adj, vis, st, i);
  }
}

//3.Distance array and stack emptying.
vector<int> dist(n, INT_MAX);

dist[0] = 0; //considering 0 ad the srcnode.
while(!st.empty()) {
  auto temp = st.top();
  st.pop();
  //go to neighbour nodes.
  for(auto it: adj[temp]) {
    int v = it.first;
    int wt = it.second;
    dist[v] = min(dist[v], dist[temp] + wt);
  }
}
return dist;
}

int main() {
  
}
