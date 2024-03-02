#include<iostream>
#include<vector> 
using namespace std;
template<typename T>
class Graph{
  private:
    void dfs(int node, int vis[], vector<int> &ans, vector<int> adj[]) {
        vis[node] = 1;
        ans.push_back(node);   
        for(auto neighbour: adj[node]) {
            if(!vis[neighbour]) {
                dfs(neighbour,vis,ans,adj);
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V + 1] = {0};
        vector<int> ans;
        //DO not use for loop
        dfs(0,vis,ans,adj);
        return ans;
    }
};

int main()
{
  vector<int> adj[]  = {{1,2}, {0, 2}, {0, 1}};
  Graph<int> g;
  int V = 3;
  vector<int> dfs = g.dfsOfGraph(V, adj);
  for(int it: dfs ) {
    cout<<it<<" ";
  }
}
