#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    //Distance array
    vector<vector<int>> dist(n , vector<int> (n, 1e9));
    queue<pair<int, pair<int, int>>>q;
    q.push({1, {0 , 0}});
    dist[0][0] = 0;

    if(grid[0][0] == 1) return -1;
    else if(n == 1) return 1;

    int delr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int delc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        int d = temp.first;
        int r = temp.second.first;
        int c = temp.second.second;

        for(int i = 0; i < 8; ++i ) {
            int x = r + delr[i];
            int y = c + delc[i];
            if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && dist[x][y] > 1 + d) { 
                if(x == n -1 && y == n - 1) return d+1;
                dist[x][y] = 1 + d;
                q.push({d+1, {x, y}});
            }
        }
    }
    return -1;
}

int main() {

vector<vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 0, 1}};
cout<<shortestPathBinaryMatrix(grid);

}