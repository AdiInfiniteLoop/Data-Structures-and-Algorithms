#include<bits/stdc++.h>
using namespace std;

//1 <= n <= 1000, 1 <= W <= 1000

int knapsack(vector<int> &wt, vector<int> &val, int W, int n, int **dp) {
    if (W <= 0 || n <= 0) return 0;
    if(dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W) {
        // Pick + NotPick
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1, dp), knapsack(wt, val, W, n - 1, dp));
    } else {
        return dp[n][W] = knapsack(wt, val, W, n - 1, dp);
    }
}

int main() {
    vector<int> wt = {4, 5, 1};
    vector<int> val = {1, 2, 3};
    int W = 4;
    int n = 3;
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; ++i) dp[i] = new int[W + 1];

    for (int i = 0; i <= n; ++i) {
    dp[i] = new int[W + 1];
    for (int j = 0; j <= W; ++j) {
        dp[i][j] = -1;
    }
}

    int maxProfit = knapsack(wt, val, W, n, dp);
    cout << maxProfit;

    return 0;
}
