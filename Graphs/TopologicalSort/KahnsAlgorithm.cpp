#include<bits/stdc++.h>
using namespace std;



/* Kahn's Algorithm: Finding the Indegree using Breath-First Search */

vector<int> kahns(vector<int> adj[], int &n) {
    vector<int> indeg = {0};
    for(int i = 0; i < n; ++i) {
        for(int it: adj[i]) {
            indeg[it]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int it: adj[node]) {
            if(--indeg[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main() {

//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;

	vector<int> ans = kahns(adj, V);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;


}