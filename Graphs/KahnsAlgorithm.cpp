#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

template <class T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;
    unordered_map<T, list<pair<T, int>>> adjListWeighted;

    void addEdge(T u, T v, bool bidirected) {
        adjList[u].push_back(v);
        if (bidirected) {
            adjList[v].push_back(u);
        }
    }

    void addEdge(T u, T v, int weight, bool bidirected) {
        adjListWeighted[u].push_back({v, weight});
        if (bidirected) {
            adjListWeighted[v].push_back({u, weight});
        }
    }

    void printAdjacencyList() {
        for (pair<T, list<T>> node : adjList) {
            cout << node.first << ": ";
            for (T &it : node.second) {
                cout << it << " ";
            }
            cout << endl;
        }
    }

    void printAdjacencyListWeighted() {
        for (pair<T, list<pair<T, int>>> node : adjListWeighted) {
            cout << node.first << ": ";
            for (auto neighborNodes : node.second) {
                cout << "(" << neighborNodes.first << ", " << neighborNodes.second << ")  ";
            }
            cout << "\n";
        }
    }

    void KahnsAlgorithm(vector<T> &ans) {
        unordered_map<T, int> indegree;
        for (auto it : adjList) {
            auto node = it.first;
            for (auto neighbour : adjList[node]) {
                indegree[neighbour]++;
            }
        }
        queue<T> q;
        for (auto it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            ans.push_back(temp);
            for (auto it : adjList[temp]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
    }

    void KahnsAlgo(vector<T> &ans) {
        queue<T> q;
        unordered_map<T, int> indegree;
        for (auto it : adjList) {
            auto srcnode = it.first;
            for (auto neighbour : adjList[srcnode]) {
                indegree[neighbour]++;
            }
        }

        for (auto it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }
        while (!q.empty()) {
            auto frntnode = q.front();
            ans.push_back(frntnode);
            q.pop();
            for (auto neighbour : adjList[frntnode]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
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

    vector<int> ans;
    g.KahnsAlgorithm(ans);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}
