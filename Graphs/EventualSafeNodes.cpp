#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0); 

    for (int i = 0; i < e; ++i) {
        for (auto it : edges[i]) {
            g[it].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for (auto it : g[temp]) {
            if (--indeg[it] == 0) {
                q.push(it);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


int main() {
    int n = 5; // Number of nodes
    int e = 6; // Number of edges
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 4}, {2, 4}, {4, 5}};

    vector<int> result = safeNodes(edges, n, e);

    cout << "Topologically sorted order: ";
    for (int node : result) {
        cout << node << " ";
    }

}