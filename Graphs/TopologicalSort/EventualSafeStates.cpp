#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    /* Have to reverse the graph edges as we cannot take outdegree here */

    int V = graph.size();
    vector<vector<int>> g(V);
    vector<int> indeg(V);
    for(int i = 0; i < V; ++i) {
        for(auto it: graph[i]) {
            g[it].push_back(i);
            indeg[i]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; ++i) {
        if(indeg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it: g[temp]) {
            if(--indeg[it] == 0) q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
vector<int> ans = eventualSafeNodes(graph);
for(int &it: ans) {
    cout<<it<<" ";
}


}