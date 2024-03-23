#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indeg(numCourses);
    vector<vector<int>> graph(numCourses);
    int V = prerequisites.size();
    for(auto it:prerequisites) {
        graph[it[1]].push_back(it[0]);
        indeg[it[0]]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; ++i) {
        if(indeg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it: graph[temp]) {
            if(--indeg[it] == 0) q.push(it);
        }
    }
    if(ans.size() != numCourses) return {}; // Check for cycles
    return ans;
}

int main() {
    vector<vector<int>> prerequisites = {{1,0}, {2, 0}, {3,1}, {3, 2}};
    int numCourses = 4;
    vector<int> ans = findOrder(numCourses, prerequisites);
    for(int &it: ans) cout<<it<<" ";
    return 0;
}
