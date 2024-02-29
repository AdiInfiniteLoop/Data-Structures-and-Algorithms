#include<iostream>
#include<vector>
#include<stack>
using namespace std;  
  
void dfs(vector<vector<int>> &graph, int* vis, int node, stack<int> &st) {
  vis[node] = 1;

  for(int j = 0; j < graph[node].size(); ++j) {
    if(vis[graph[node][j]] == -1) {
      dfs(graph, vis, graph[node][j], st);
    }
  }
  st.push(node);
  
}
void topoSort(vector<vector<int>> &graph) {
  stack<int> st;
  int n = graph.size();
  int* vis = new int[n];
  for(int i = 0; i < n; ++i) vis[i] = -1;
  for(int i = 0; i < n; ++i) {
    if(vis[i] == -1) {
      dfs(graph, vis, i,st);
    }
    
  }

  // cout<<"data is\n";
  while(!st.empty()) {
    cout<<st.top()<<" ";
    st.pop();
  }
}



int main() {
  vector<vector<int>> graph{ {1}, {2}, {3,4}, {}, {5}, {} };
  topoSort(graph);

}
/* 0 -> 1 -> 2-> 4 - > 5
             |
             v
             3  */