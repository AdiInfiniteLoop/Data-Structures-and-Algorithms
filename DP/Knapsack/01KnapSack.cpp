#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int W, int n) {
    if (W <= 0 || n <= 0) return 0;

    if (wt[n - 1] <= W) {
        // Pick + NotPick
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    } else {
        return knapsack(wt, val, W, n - 1);
    }
}

int main() {
    vector<int> wt = {4, 5, 6};
    vector<int> val = {1, 2, 3};
    int W = 3;
    int n = wt.size();
    int maxProfit = knapsack(wt, val, W, n);
    cout << maxProfit;

    return 0;
}
