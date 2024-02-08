#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, int j, string &s, string &t){
    if (j<0) return 1;
    if (i<0) return 0;

    if (s[i] == t[j]) 
        return solve(i-1, j-1, s, t) + solve(i-1, j, s, t);
    return solve(i-1, j, s, t);
}

int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    return solve(n-1, m-1, s, t);
}

// Memoization
int solve1(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if (j==0) return 1;
    if (i==0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i-1] == t[j-1]) 
        return dp[i][j] = solve1(i-1, j-1, s, t, dp) + solve1(i-1, j, s, t, dp);
    return dp[i][j] = solve1(i-1, j, s, t, dp);
}

int numDistinct2(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solve1(n, m, s, t, dp);
}

// Tabulation
int numDistinct3(string s, string t){
    int n = s.size(), m = t.size();

    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return (int)dp[n][m];
}

// Space Optimization - O(2M)
int numDistinct3(string s, string t){
    int n = s.size(), m = t.size();

    vector<double> prev(m+1, 0), cur(m+1, 0);
    prev[0] = cur[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                cur[j] = prev[j - 1] + prev[j];
            else
                cur[j] = prev[j];
        }
        prev = cur;
    }

    return (int)prev[m];
}

// Space Optimization - O(N)
int numDistinct3(string s, string t){
    int n = s.size(), m = t.size();

    vector<double> dp(m+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            if (s[i - 1] == t[j - 1])
                dp[j] = dp[j - 1] + dp[j];
        }
    }

    return (int)dp[m];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}