#include<iostream>
#include<vector> 
using namespace std;
template<typename T>
class Graph{
  private:

    bool checkForCycle(T node, T parent, T vis[], vector < T > adj[]) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkForCycle(it, node, vis, adj))
            return true;
        } else if (it != parent)
          return true;
      }

      return false; 


    }
  public:
    bool isCycle(T V, vector < T > adj[]) {
      int vis[V+1] = {0};
      for (auto i = 0; i < V; i++) {
        if (!vis[i]) {
          if (checkForCycle(i, -1, vis, adj)) return true;
        }
      }

      return false;
    }
};

int main()
{
  vector<int> adj[]  = {{1}, {2,5}, {6,4}};
  Graph<int> g;
  if(g.isCycle(3, adj)) cout<<"Cycle is Present";
  else cout<<"Cycle is absent";
}
