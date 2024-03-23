#include<bits/stdc++.h>
using namespace std;

class Regions {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<char>> aux(n, vector<char>(m, 'X'));

        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'O' && (i == n-1 || i == 0 || j == m-1 || j == 0)) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            for(int i = 0; i < 4; ++i) {
                int nr = x + delr[i];
                int nc = y + delc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i = 0;i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    aux[i][j] = 'X';
                }
                else if(vis[i][j]) {
                    aux[i][j] = 'O';
                }
                else continue;
            }
        }
        
        board = aux;
    }
};


int main() {
  Regions r;
  vector<vector<char>> graph { {'X', 'O', 'X'}, {'X', 'O', '0'}, {'X','X','X'} };
  r.solve(graph);
}
