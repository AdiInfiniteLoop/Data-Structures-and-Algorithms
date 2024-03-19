#include<iostream>
#include<queue>
#include<vector>

using namespace std;


vector<int> dijkstra(vector<vector<int>> &edges, int S) {
    int n = edges.size();
    vector<pair<int, int>> adj[n];
    vector<int> dist(n, 1e9);
    for(const auto ed: edges) {
        adj[ed[0]].push_back({ed[1], ed[2]});
    }

    std::priority_queue<pair<int, int> , vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while(!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int node = temp.second;
        int wt = temp.first;

        for(auto it: adj[node]) {
            if(dist[it.second] > wt + it.first) {
                dist[it.second] = wt + it.first;
                pq.push({wt+it.first, it.second});
            }
        }
    }
    for(int &it: dist){
        if(it == 1e9) it = -1;
    }
    return dist;
}


int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 2},
        {2, 4, 3},
        {3, 4, 1}
    };

    int source = 0; // Source vertex

    vector<int> distances = dijkstra(edges, source);

    // Output the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Vertex " << i << ": " << distances[i] << '\n';
    }

    return 0;
}
