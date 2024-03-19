#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits.h>

using namespace std;

void dfs(vector<pair<int, int>> adj[], int* vis, int node, stack<int> &st) {
    vis[node] = 1;

    for(auto ed: adj[node]){
        int it = ed.first;
        if(vis[it] == -1) {
            dfs(adj, vis, it, st);
        }
    }
    st.push(node);
}

void topoSort(vector<vector<int>> &edges, int src) { 
    int n = edges.size();
    int* vis = new int[n];
    stack<int> st;

    vector<pair<int, int>> adj[n];
    for(const auto ed: edges) {
        int u = ed[0];
        int v = ed[1];
        int wt = ed[2];
        adj[u].push_back({v, wt});
    }

    for(int i = 0; i < n; ++i ) {
        vis[i] = -1;
    }
    for(int i = 0; i < n; ++i ) {
        if(vis[i] == 0-1)  {
            dfs(adj, vis, i, st);
        }
    }

    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();   
    }
}



int main() {
    
    vector<vector<int>> edges = { {0,1,4}, {1,2,5}, {2, 1, 7}};
    topoSort(edges, 0);
}





