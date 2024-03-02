#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<stack>
#include<list>
using namespace std;
template <class T>
class Graph {
    public:
        unordered_map<T, list<T > > adjList;
        unordered_map<T, list<pair<T, int> > > adjListWeighted;

        void addEdge(T u, T v, bool bidirected) {
            //bidirected==1. bidirected
            //bidirected==0. unirectected
            adjList[u].push_back(v);
            if(bidirected) {
                adjList[v].push_back(u);
            }
        }
        //Overloaded the method
        void addEdge(T u, T v, int weight, bool bidirected) {
          adjListWeighted[u].push_back({v,weight});
          if(bidirected) {
            adjListWeighted[v].push_back({u,weight});
          }
        }

        void printAdjacenyList() {
            for(pair<T, list<T>> node: adjList) {
                cout<<node.first<<": ";
                for(T &it: node.second) {
                    cout<<it<<" ";
                } 
                cout<<endl;
            }
        }

        void printAdjacenyListWeighted() {
          for(pair<T, list<pair<T, int> > > node: adjListWeighted) {
            cout<<node.first<<": ";
            for(auto neightbourNodes: node.second) {
              cout<<"("<<neightbourNodes.first<<", "<<neightbourNodes.second<<")  ";
            }
            cout<<"\n";
          }
        }

void dfs(int* vis, T node, stack<T> &st) {
    vis[node] = 1;

    for(auto neighbour: adjList[node]) {
        if(!vis[neighbour] == -1) {
            dfs(vis, neighbour, st);
        }
    }
    st.push(node);          
}

void topoSort() {
    stack<T> st;
    int n = adjList.size();
    int* vis = new int[n];
    
    for(int i = 0; i < n; ++i) {
        vis[i] = -1; // Set all vertices as not visited
    }

    for(auto node: adjList) {
        if(vis[node.first] == 0) {
            dfs(vis, node.first, st);
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}


};
  


int main() {
    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 6, 0);
    g.addEdge(4, 7, 0);
    g.addEdge(4, 8, 0);
    g.addEdge(6, 7, 0);
    g.addEdge(7, 10, 0);
    g.addEdge(8, 9, 0);
    g.addEdge(8, 10, 0);
  
    g.topoSort();

    return 0;
}


/* 0 -> 1 -> 2-> 4 - > 5
             |
             v
             3  */