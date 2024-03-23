#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    
// Define priority queue with a custom comparison function
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Push starting point into the priority queue
    pq.push({0, {0, 0}});

    // Get the size of the grid
    int n = heights.size();
    int m = heights[0].size();

    // Initialize distance array
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;

    // Define directions
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, -1, 0, 1};

    // Dijkstra's algorithm
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int diff = temp.first;
        int r = temp.second.first;
        int c = temp.second.second;

        if(r == n-1 && c == m-1) return diff;
        // Iterate over neighbors
        for (int i = 0; i < 4; ++i) {
            int x = delr[i] + r;
            int y = delc[i] + c;
            
            // Check boundary and update distance
            if (x < n && x >= 0 && y < m && y >= 0) {
                int newmx = max(abs(heights[x][y] - heights[r][c]), diff); //onthe way reaching last node we are updatin gdiff which is higher

                if(newmx < dist[x][y]) {
                    dist[x][y] = newmx;
                    pq.push({dist[x][y], {x, y}});
                }
                // Push the updated distance and coordinates into the priority queue
            }
        }
    }
    return -1; // In case destination is not reachable
}

int main() {
vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

cout<<minimumEffortPath(heights);


}