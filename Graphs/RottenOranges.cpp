#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Graph {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        /* Creating Visited Array */
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int cnt = 0; 
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1};
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            int x = temp.first.first;
            int y = temp.first.second;
            int time = temp.second;
            //  cnt = max(cnt, time); iske bina bhi hota hain. at the end we need
            cnt = time;

            for(int i = 0; i < 4; ++i) {
                int nr = x + delr[i];
                int nc = y + delc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    vis[nr][nc] = 2;
                    q.push({{nr,nc},time + 1});
                }
            }
        }
        
        for(int i = 0;i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return cnt;
    }
};

int main() {
Graph g;
vector<vector<int>> grid = {{1, 0, 1}, {1, 1, 2}};
cout<<g.orangesRotting(grid);
}