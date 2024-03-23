#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    queue<pair<int, int>> q;
    q.push({0, k});
    vector<int> dist(n + 1 ,1e9);
    dist[k] = 0;
    //Creation of adjaceny list
    vector<pair<int, int>> adj[n + 1];
    for(const auto it: times){
        adj[it[0]].push_back({it[1], it[2]});
    }

    while(!q.empty()) {
        auto [d, node] = q.front();
        q.pop();

        for(const auto &it: adj[node]) {
            int neighbour = it.first;
            int time = it.second;
            if(dist[neighbour] > time + d) {
                dist[neighbour] = time + d;
                q.push({time+d, neighbour});
            }
        }
    }
    int mx = INT_MIN;
    for(int i = 1; i < dist.size(); ++i) {
        if(dist[i] == 1e9) return -1;
        mx = max(mx, dist[i]);
    }
    return mx;
}
int main() {
    vector<vector<int>> times = {{2, 1,1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    cout<<networkDelayTime(times, n, k);


return 0;
}