#include <bits/stdc++.h>
using namespace std;

int seg[10001];

void buildtree(int i, int l, int r, vector<int> &v) {
    if(l == r) {
        seg[i] = v[l];
        return;
    }
    int mid = (r - l)/2 + l;
    buildtree(2*i + 1, l, mid, v);
    buildtree(2*i + 2, mid + 1, r, v);
    seg[i] = seg[2*i + 1] + seg[2*i + 2];
}

int main() {
    vector<int> v = {3, 1, 2, 7, 1};
    int n = v.size();

    memset(seg, 0, sizeof(seg));

    buildtree(0, 0, n - 1, v);

    for(int i = 0; i < 2*n; ++i) cout << seg[i] << " ";
    cout << endl;
    //TC:O(2*N)
    //SC: O(2*N) + O(log(N))
}
