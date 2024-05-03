#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string &a, string &b, int n, int m) {
    if(n == 0 || m == 0) return 0;

    if(a[n - 1] == b[m - 1]) {
        return longestCommonSubsequence(a, b, n - 1, m- 1) + 1;
    }
    else {
        return max(longestCommonSubsequence(a, b, n - 1, m), longestCommonSubsequence(a, b, n, m- 1));
    }
}
int main() {

string a = "abcdg";
string b = "abcdfhr";
int m = a.size();
int n = b.size();
cout <<  longestCommonSubsequence(a, b, m, n);
return 0;
}