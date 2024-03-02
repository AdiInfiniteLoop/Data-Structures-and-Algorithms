#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph {
  private:
    unordered_map<T , list<T> > adjList;
  public:
    void addEdge(T u, T v, bool bidirected) {
      adjList[u].push_back(v);
      if(bidirected) {
        adjList[v].push_back(u);
      }
    }

    void printAdjacencyList() {
      for(pair<T, list<T> > node: adjList) {
       
        cout<<node.first<<": ";
        for(auto neighbour: node.second) {
          cout<<neighbour<<" ";
        }
        cout<<"\n";
      }
    }
    
  void bfs(T srcnode,  unordered_map<T, bool > &vis) {
    queue<T> q;
    q.push(srcnode);

    while(!q.empty()) {
      int n = q.size();
      for(int i = 0; i < n; ++i) {
        T front = q.front();
        q.pop();
        //Print the node
        cout<<front<<" ";
        vis[front] = true;

        //Print neighours
        for(T neighbour: adjList[front]) {
          if(!vis[neighbour]) {
            q.push(neighbour);
            vis[neighbour] = true;
          }
        }
      }
      cout<<"\n";
    }
  }

  void dfs(T srcnode, unordered_map<T,bool> &vis) {
    vis[srcnode] = true;
    cout<<srcnode<<" ";
    for(auto neighbour: adjList[srcnode]) {
      if(!vis[neighbour]) {
        dfs(neighbour, vis);
      }
      cout<<"";
    }
      
  }

};
 


int main() {
  Graph<int> g1;
  g1.addEdge(1,4,1);
  g1.addEdge(2,5,1);
  g1.addEdge(3,6,1);
  g1.addEdge(4,5,1);
  g1.addEdge(5,2,1);
  g1.addEdge(6,4,1);
  g1.addEdge(3,6,1);
  g1.addEdge(2,4,1);
  g1.addEdge(1,6,1);

  g1.printAdjacencyList();
   unordered_map<int, bool > vis;
    cout<<"BFS\n";
   for(int i = 0;i < 6; ++i) {
     if(!vis[i]) {
       g1.bfs(1, vis);
     }
   }
   cout<<"\nDFS\n";
   unordered_map<int, bool> vis2;

     for(int i = 0; i < 6; ++i) {
     if(!vis2[i]) {
       g1.dfs(1, vis2);
     }
   }


}
