#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>


using namespace std;

vector<int> shortestPathinUndirectedUnitWeightGraph(vector<vector<int>> &edges, int src) {
    // 1.Create Graph 
    int n = edges.size();
    std::vector<int> adj[n];
    for(const auto ed: edges) {
        int u = ed[0];
        int v = ed[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //2.Queue Creation which stores the node and its distance.
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        int node = temp.first;
        int wt = temp.second;
        for(int it: adj[node]) {
            if(wt +1 < dist[it]) {
                dist[it] = wt + 1;
                q.push({it, wt+1});
            }
        }
        
    }
    for(int &it: dist) 
    {
        if(it == 1e9) it = -1;
    }
    return dist;
}


int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    int src = 1;
    vector<int> dist  = shortestPathinUndirectedUnitWeightGraph(edges, src);

    for(int it: dist) {
        cout<<it<<" ";
    }

}