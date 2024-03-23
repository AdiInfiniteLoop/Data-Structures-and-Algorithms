#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
//Bi Directional
using namespace  std;
template<class T>
class Graph {
  private:
    bool detectCycle(int V, vector<int> adj[]) {
        queue<int> q;
        unordered_map<int,  bool> vis;
        q.push(1);
        vis[1] = 1;
        unordered_map<int, int> pmap; //child-parent
        pmap[1] = -1;
        while(!q.empty()) {
            int n = q.size();
                int temp = q.front();
                q.pop();
                for(int it: adj[temp]) {
                  if (!vis[it]) {
                    pmap[it] = temp;
                    q.push(it);
                    vis[it] = 1;
                  }
                 else if(pmap[temp] != it){ //front node(temp)'s parent is not the neighbour.(parent != neighbournode)
                      return true;
                  }
                }
            }   
            
        
        return false;
    }
        public:
        unordered_map<T, list<T> > adjList;
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
};


int main() {

Graph<int> g;
g.addEdge(1,2,1);
}


/* Case is why a node is already visited when it is not even the parent */