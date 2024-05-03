#include<bits/stdc++.h>
using namespace std;


int longestCommonSubstr (string a, string b, int n, int m) {
        int dp[n + 1][m + 1];
        for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int i = 0; i <= m; ++i) dp[0][i] = 0;

        for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] =0;
            
        }
        }
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                ans = max(ans, dp[i][j]);
        
    return ans;
}

int main() {
    string a = "abcdgh";
    string b = "acdghr";
    int n = a.size();
    int m = b.size();
    cout << longestCommonSubstr(a, b, n, m);


return 0;
}