#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S]  = 0;
    for(int i = 0; i < V - 1; ++i) {
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1}; 
        }
    }

    return dist;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {2, 1, 1}, {3, 2, 5}};

    int S = 0;

    vector<int> dist = bellman_ford(V, edges, S);

    if (dist[0] == -1) {
        cout << "Graph contains a negative cycle!" << endl;
        return 0; // Exit if negative cycle is found
    }
    cout << "Vertex \t\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }

    return 0;
}
