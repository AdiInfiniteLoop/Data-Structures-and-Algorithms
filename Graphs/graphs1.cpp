#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template <class T>
class Graph {
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
       system("CLS");
    //ADJACENCY LIST
    /* Unidirectional graph */
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(0,3,0);
    g.addEdge(3,2,0);
    g.addEdge(2,1,0);
    g.addEdge(3,1,0);

    g.printAdjacenyList();

    /*Bidirectional * Weighted*/ 
    Graph<int> g2;
    g2.addEdge(0,1,12,1);
    g2.addEdge(0,3,24,1);
    g2.addEdge(3,2,36,1);
    g2.addEdge(2,1,48,1);
    g2.addEdge(3,1,60,1);
    cout<<"(Neightbour Node, Weight of Edge)\n" ;
    g2.printAdjacenyListWeighted();

    /* Sugoi template */
    Graph<char> g3;
    g3.addEdge('a','b',1);
    g3.addEdge('c','d',1);
    g3.addEdge('d','c',1);
    g3.addEdge('b','c',1);
    g3.addEdge('a','d',1);

    g3.printAdjacenyList();



    //ADJACENCY MATRIX
/*     int n;
    cout<<"Enter number of nodes\n";
    cin>>n; 

    int edges;
    cout<<"Enter number of edges\n";
    cin>>edges;

    vector<vector<int> > adj(n, vector<int> (n, 0));

    for(int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    } */

    
 
}
