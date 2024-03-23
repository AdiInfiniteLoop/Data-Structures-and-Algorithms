#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //Set takes O(E Log V)
    //Queue takes O(E)
    int m = flights[0].size();
    vector<pair<int, int>> adj[n];
    //1.Creating a graph
    for(const auto it: flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> st;
    st.push({0, {src, 0}});   //stop, node, distance
    while(st.size() > 0) {
        auto temp = st.front();
        st.pop();
        int stops = temp.first;
        if(stops > k) {
            continue;
        }
        int node = temp.second.first;
        int d = temp.second.second;

        for(auto it: adj[node]) {
            int v = it.first;
            int wt = it.second;
            if(dist[v] > d + wt) {
                dist[v] = d + wt;
                st.push({stops+1, {v, d+ wt}});
            }
        }
    }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
}

int main() {

vector<vector<int>> flights = {{0, 2, 200}, {0, 1, 200}, {2, 1, 500}};
cout<<findCheapestPrice(3, flights, 0, 2, 2);


}