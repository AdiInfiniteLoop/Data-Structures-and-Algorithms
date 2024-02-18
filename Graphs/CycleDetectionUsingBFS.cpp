#include<iostream>

using namespace  std;

class Graph {
  public:
    bool detectCycle(int V, vector<int> adj[]) {
        queue<int> q;
        unordered_map<int,  bool> vis;
        q.push(1);
        vis[1] = 1;
        unordered_map<int, int> pmap; //child-parent
        pmap[1] = -1;
        while(!q.empty()) {
            int n = q.size();
                int temp = q.front();
                q.pop();
                for(int it: adj[temp]) {
                  if (!vis[it]) {
                    pmap[it] = temp;
                    q.push(it);
                    vis[it] = 1;
                  }
                 else if(pmap[temp] != it){ //front node(temp)'s parent is not the neighbour.
                      return true;
                  }
                }
            }   
            
        
        return false;
    }
};
