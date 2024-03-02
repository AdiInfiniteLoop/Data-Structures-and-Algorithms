#include<iostream>
#include<vector>
using namespace std;

class Graph{
public:
    bool dfs(int node, bool color, int &n, vector<vector<int>> &graph, int vis[]) {
        vis[node] = color;

        for(int i = node; i < n; i++) {
            for(int j = 0;j < graph[node].size(); j++) {
                if(vis[graph[node][j]] == -1) {
                    if(dfs(graph[node][j], !color, n, graph, vis) == false) return false; //this line similar to Number of Provinces
                }
                else if(vis[node] == vis[graph[node][j]]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        int *vis = new int[n];
        for(int i = 0; i < n; ++i) vis[i] = -1;

        for(int i = 0; i < n; ++i) {
            if(vis[i] == -1) {
                if(dfs(i, 0, n, graph, vis) == false) return false;
            }
        }
    return true;
    }
};


int main() {
  vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  Graph* g;
  if(g->isBipartite(graph)) cout<<"It is Bipartite";
  else cout<<"It is not Bipartite";
}
