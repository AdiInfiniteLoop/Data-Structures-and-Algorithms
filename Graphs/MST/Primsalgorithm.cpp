#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Function to create an adjacency list representation of a graph
vector<vector<pair<int, int>>> createAdjList(int V) {
    vector<vector<pair<int, int>>> adj(V);
    return adj;
}

// Function to add an edge to the adjacency list
void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt) {
    adj[u].push_back({v, wt}); // Add edge with weight to adjacency list of u
    adj[v].push_back({u, wt}); // Add edge with weight to adjacency list of v (undirected graph)
}

// Function to find the minimum spanning tree using Prim's algorithm
vector<pair<int, int> > MinimumSpanningTree(vector<vector<pair<int, int> > > &adj)  {
  int V = adj.size();
  vector<int> vis(V, 0);
  vector<int> parents(V, -1);
  parents[0] = -1;
  vector<pair<int, int> > edges;
  priority_queue<pair<int, int> , vector<pair<int, int> > ,greater<pair<int, int> > > pq;
  pq.push({0, 0}); //wt, node

  while (!pq.empty()) {
    auto temp = pq.top();
    pq.pop();
    int node = temp.second;
    size_t wt = temp.first;
    if(vis[node]) continue;
    if(parents[node] != -1) {
      edges.push_back({parents[node], node});
    }
    vis[node] = 1;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int newwt = it.second;
            if (!vis[neighbor]) {
                pq.push({newwt, neighbor});
                parents[neighbor] = node;
            }
        }
  }
  return edges;
}



vector<pair<int, int> > MinimumSpanningTreeUsingSet(vector< vector< pair< int, int > > >&adj) {
  set<pair<int, pair<int, int> > > st;
  st.insert({0, {0, -1}});
  int n = adj.size();
  vector<int> vis(n, 0);
  vector< pair<int, int> > mst;

  int sum = 0;
  while(st.size() > 0) {
    auto temp = *(st.begin());
    st.erase(st.begin());
    int wt = temp.first;
    int node = temp.second.first;
    int parent = temp.second.second;
    if(vis[node]) continue;
    vis[node] = 1;
    if(parent != -1) {
     mst.push_back({parent, node});
    
    sum += wt;
    for(auto it: adj[node]) {
      int v = it.first;
      int newwt = it.second;
      if(!vis[v]) {
        st.insert({newwt, {v, node}});
      }
    }
  }
  }
  return mst;
}

int main() {
    int V = 5; // Number of vertices in the graph

    vector<vector<pair<int, int>>> adj = createAdjList(V);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 4, 4);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 3, 4, 1); 

    vector<pair<int, int> > MSTEdges = MinimumSpanningTreeUsingSet(adj);

    // Printing the edges of the minimum spanning tree
    cout << "Edges of the minimum spanning tree:" << endl;
    for (auto edge : MSTEdges) {
        cout << edge.first << " - " << edge.second << endl;
    }

}




/*
vector<pair<int, int>> MinimumSpanningTree(vector<vector<pair<int, int>>>& adj)  {
    int V = adj.size();
    vector<int> vis(V, 0);
    vector<int> parents(V, -1);
    parents[0] = -1;
    vector<pair<int, int>> edges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {wt, node}

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int node = temp.second;
        int wt = temp.first;
        if (vis[node]) continue;
        if (parents[node] != -1) {
            edges.push_back({parents[node], node});
        }
        vis[node] = 1;

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int newwt = it.second;
            if (!vis[neighbor]) {
                pq.push({newwt, neighbor});
                parents[neighbor] = node;
            }
        }
    }
    return edges;
}
*/
