#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph {
public:
    vector<vector<int>> matrixUpdate(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis (m, vector<int> (n, 0));
        vector<vector<int>> dist (m, vector<int> (n, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i,j}, 0});
                    dist[i][j] = 0;
                }
            }
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        while(!q.empty()) 
        {
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int d = temp.second;
            dist[x][y] = d;

            for(int i = 0; i < 4; ++i) {
                int nr = x + delr[i];
                int nc = y + delc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n &&! !vis[nr][nc]) {
                    q.push({{nr, nc}, d + 1});
                    vis[nr][nc] = 1;
                }
            }
        }

    return dist;
    }
};


int main() {
    Graph g;
    vector<vector<int>> adjMat {{0,1,1}, {1,0,0}};
    g.matrixUpdate(adjMat);
}
