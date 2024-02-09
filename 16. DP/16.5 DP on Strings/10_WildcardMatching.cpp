#include <bits/stdc++.h>
using namespace std;

// Recursion
bool solve(int i, int j, string &s, string &p){
    if (i<0 && j<0) return true;
    if (j<0 && i>=0) return false;
    if (i<0) {
        for (int x=0; x<=j; x++) if (p[j] != '*') return false;
        return true;
    }

    if (s[i] == p[j] || p[j] == '?') return solve(i-1, j-1, s, p);
    if (p[j] == '*') {
        bool m1 = solve(i, j-1, s, p);    // empty
        bool m2 = solve(i-1, j, s, p);    // more matching

        return m1 || m2;
    }

    return false;
}

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    return solve(n-1, m-1, s, p);
}

// Memoization
bool solve1(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return true;
    if (j == 0 && i > 0) return false;
    if (i == 0){
        for (int x=1; x<=j; x++) if (p[x-1] != '*') return false;
        return true;
    }
        
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i-1] == p[j-1] || p[j-1] == '?')
        return dp[i][j] = solve1(i - 1, j - 1, s, p, dp);
    if (p[j-1] == '*') {
        bool m1 = solve1(i, j - 1, s, p, dp);     // empty
        bool m2 = solve1(i - 1, j, s, p, dp);     // more matching

        return dp[i][j] = m1 || m2;
    }

    return dp[i][j] = false;
}

bool isMatch1(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve1(n, m, s, p, dp);
}

// Tabulation
bool isMatch2(string s, string p){
    int n = s.size(), m = p.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    // for (int i=1; i<=n; i++) dp[i][0] = false;
    for (int j=1; j<=m; j++){
        if (p[j-1] != '*') break;
        dp[0][j] = true;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*'){
                bool m1 = dp[i][j-1];    // empty
                bool m2 = dp[i-1][j];    // matching

                dp[i][j] = m1 || m2;
            } else dp[i][j] = false;
        }
    }

    return dp[n][m];

}

// Space Optimization
bool isMatch2(string s, string p){
    int n = s.size(), m = p.size();

    // vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    // dp[0][0] = true;
    // for (int i=1; i<=n; i++) dp[i][0] = false;
    // for (int j=1; j<=m; j++){
    //     if (p[j-1] != '*') break;
    //     dp[0][j] = true;
    // }

    vector<bool> prev(m+1, false), cur(m+1, false);
    prev[0] = true;
    for (int j=1; j<=m; j++){
        if (p[j-1] != '*') break;
        prev[j] = true;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1] == p[j-1] || p[j-1] == '?') cur[j] = prev[j-1];
            else if (p[j-1] == '*'){
                bool m1 = cur[j-1];    // empty
                bool m2 = prev[j];    // matching

                cur[j] = m1 || m2;
            } else cur[j] = false;
        }

        prev = cur;
    }

    return prev[m];

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}