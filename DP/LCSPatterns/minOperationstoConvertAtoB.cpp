/* The two valid operations are : Insertion and Deletion */
/* Parent Problem: dp -> LCS */
/* Instead of directly converting from string a to string b, find the longest common subsequence . */
/* As Deletion = a.size() - lcs.size() && Insertion = b.size() - lcs.size() */

#include<bits/stdc++.h>
using namespace std;

int main() {

    string a = "abcdgh";
    string b = "acdghr";
        int n = a.size();
    int m = b.size();
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; ++i) dp[i][0] = 0;
    for(int i = 0; i <= m; ++i) dp[0][i] = 0;

    for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
        if(a[i - 1] == b[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";

    int i = n, j = m;
    while(i >= 0 || j >= 0) {
        if(a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    cout << (n - 2*(ans.size() - 1) + m);   //ans.size() - 1 to remove the null character at the end of the string.

return 0;
}