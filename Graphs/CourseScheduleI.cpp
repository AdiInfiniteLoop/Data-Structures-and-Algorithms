#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class CourseScheduleI {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<vector<int>> graph(numCourses);
        int V = prerequisites.size();
        for(auto it:prerequisites) {
            graph[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indeg[i] == 0)q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            cnt++;
            for(auto it: graph[temp]) {
                if(--indeg[it] == 0)q.push(it);
            }
        
    }
    return (cnt == numCourses);
    }
};


int main() {
CourseScheduleI g;
vector<vector<int>> prereq = {{1, 0}, {0,1}};
cout<<g.canFinish(2, prereq);

}