#include<iostream>
#include<vector>

using namespace std; 

class Graph {
private:
    bool checkusingdfs(int node, vector<int> adj[], int vis[], int parent) {
        
        vis[node] = 1;
        for(auto  it: adj[node]) {
            if(!vis[it]) {
                if(checkusingdfs(it, adj, vis, node))
                    return 1;
            }
            else if(it != parent) return true;
        }
        return false;
    }
public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int parent = -1;
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                bool ans = checkusingdfs(i, adj, vis, parent);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};
//using in vis is faster than unordered_map<int, bool> vis

int main() {
  Graph g;
  vector<int> adj[] = {{1,2}, {0,2}, {1,0}};
int   V = 3;
cout<<g.detectCycle(V, adj);
}
