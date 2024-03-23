#include<iostream>
#include<set>
#include<vector>



using namespace std;

vector<int> dijsktraUsingSet(vector<vector<int>> &edges, int src) {
    int n = edges.size();
    set<pair<int, int> > st;
    vector<int> dist(n, 1e9);
    vector<pair<int, int>> adj[n];
    for(const auto it: edges){
        adj[it[0]].push_back({it[2], it[1]});
    }

    st.insert({0, src});
    dist[src]= 0;
    while(!st.empty()) {
        auto temp = *(st.begin()); //st.begin() returns an itertrator/pointer and * to dereference it.
        st.erase(temp);
        int node = temp.first;
        int d = temp.second;
        for(auto it: adj[node]){
            int wt = it.first;
            int v = it.second;
            if(dist[node] > dist[v] + wt) {
                if(dist[v] != 1e9) //incase of 1e9 , directly erase it
                st.erase({dist[v], v});
                dist[v] = d+ wt;
                st.insert({d, v});
            }
        }
    }return dist;
}

int main() {

}

