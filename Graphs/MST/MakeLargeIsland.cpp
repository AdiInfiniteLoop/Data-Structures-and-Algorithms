#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
  vector<int> rank, parent, size;
public:
  DisjointSet(int n) {
    rank.resize(n+1, 0); //1-based indexing
    parent.resize(n+1, 0);
    for(int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    size.resize(n+1, 1);
  }

  int findUlp(int node) {
    if(node == parent[node]) return node;
    return parent[node] = findUlp(parent[node]); //parent[node] for Path Compression.
  }

  void UnionByRank(int u, int v) {
    int ulp_u =findUlp(u);
    int ulp_v = findUlp(v);
    if(ulp_u == ulp_v) return;
    if(rank[ulp_u] == rank[ulp_v]) {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
    else if(rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    }
    else {
      parent[ulp_v] = ulp_u;
    }
  }

  void UnionBySize(int u, int v) {
    int ulp_u = findUlp(u);
    int ulp_v = findUlp(v);

    if(ulp_u == ulp_v) return;
    else if(size[ulp_u] < size[ulp_v]) {
      size[ulp_v] += size[ulp_u];
      parent[ulp_u] = ulp_v;
    }//No need for else if as they do the same operation.
    else {
      size[ulp_u] += size[ulp_v];
      parent[ulp_v] = ulp_u;

    }
  }
};

class LargeIsland {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, -1, 0, 1};

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; ++k) {
                    int newr = i + delr[k];
                    int newc = j + delc[k];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                        int nodeno = i * n + j;
                        int adjno = newr * n + newc;
                        ds.UnionBySize(nodeno, adjno);
                    }
                }
            }
        }

        int mx = -0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                set<int> st;
                if(grid[i][j] == 1) continue;
                for(int k = 0; k < 4; ++k) {
                    int newr = i + delr[k];
                    int newc = j + delc[k];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                        // int nodeno = i * n + j;
                        int adjno = newr * n + newc;
                        st.insert(ds.findUlp(adjno));
                    }
                }  
                int sum = 0;
                for(int it: st) sum += ds.size[it];        
                mx = max(mx, sum+1);
            }
        }
        
        for(int i = 0; i < n * n; ++i) mx = max(mx, ds.size[ds.findUlp(i)]);

        return mx;
    }
};
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0}
    };

    LargeIsland islandFinder;
    int largest = islandFinder.largestIsland(grid);
    cout << "Largest Island Size: " << largest << endl;

    return 0;
}
