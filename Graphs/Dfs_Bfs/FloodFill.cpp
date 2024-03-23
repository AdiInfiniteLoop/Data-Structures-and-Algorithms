
#include<iostream>
#include<queue>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int main() {
vector<vector<int>>image;
image = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
int sr = 0;
int sc = 0;
int color = 0;

int m = image.size();
int n = image[0].size();

std:vector<std::vector<int>> newArr(m, vector<int> (n, 0));
queue<pair<int, int>> q;
int inital = 0;
//Creating Visited array.
for(int i =  0;i < m; ++i) {
    for(int j = 0;j < n; ++j) {
        newArr[i][j] = image[i][j];
    }
}
inital = image[sr][sc];
newArr[sr][sc] = color;
        
q.push({sr, sc});

for(int i =  0;i < m; ++i) {
    for(int j = 0;j < n; ++j) {
        cout<<image[i][j]<<" ";
    }
    cout<<"\n";
}
cout<<"New\n";

int delr[] = {-1, 0, 1, 0};
int delc[] = {0, -1, 0, 1};
while(!q.empty()) {
    int v = q.size();
    for(int i = 0;i < v; ++i) {
        auto temp = q.front(); q.pop();
        int x = temp.first;
        int y = temp.second;
        for(int i = 0; i < 4; ++i) {
            int nr = x + delr[i];
            int nc = y + delc[i];
          if(nr < m && nr >= 0 && nc < n && nc >= 0 && newArr[nr][nc] == inital  && newArr[nr][nc] != color) {
                newArr[nr][nc] = color;
                q.push({nr,nc});
            }
        }
    }
}


for(int i =  0;i < m; ++i) {
    for(int j = 0;j < n; ++j) {
        cout<<newArr[i][j]<<" ";
    }
    cout<<"\n";
}


 
}
