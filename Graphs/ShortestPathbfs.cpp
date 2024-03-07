
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &graphs, int src, int dest) {
  queue<int> q;
  int V = graphs.size();
  vector<int> vis(V, 0);
  vector<int> parent(V, -1);
  q.push(src);
  vis[src] = 1;

  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    for (int it : graphs[temp]) {
      if (!vis[it]) {
        q.push(it);
        parent[it] = temp;
        vis[it] = 1;
      }
    }
  }

  vector<int> ans;
  int node = dest;
  while (node != -1) {
    ans.push_back(node);
    node = parent[node];
  }
  return ans;
}

int main() {
  // Example usage
  vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2}, {3}};
  int src = 0, dest = 5;
  vector<int> result = shortestPath(graph, src, dest);

  cout << "Shortest path from " << src << " to " << dest << ": ";
  for (int i = result.size() - 1; i >= 0; --i) {
    cout << result[i] << " ";
  }

  return 0;
}

