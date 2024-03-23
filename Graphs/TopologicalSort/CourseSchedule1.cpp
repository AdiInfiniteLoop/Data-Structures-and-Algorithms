#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = prerequisites.size();
        vector<vector<int>> graph(numCourses); //must do
        vector<int> indeg(numCourses, 0);

        for(auto it: prerequisites) {
            graph[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        

        queue<int> q;
        for(int i = 0;i < numCourses; ++i ) {
            if(indeg[i] == 0) q.push(i);
        }
        
        int cnt = 0;

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            cnt++;
            for(auto it: graph[temp]) {
                if(--indeg[it] == 0) q.push(it);
            }
        }
        return (cnt == numCourses);
}

int main() {
vector<vector<int>> prerequisites = {{1,0}, {0,1}};
int numCourses = 2;
cout<<canFinish(numCourses, prerequisites);



}