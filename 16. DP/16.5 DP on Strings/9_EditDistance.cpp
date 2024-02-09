#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int i, int j, string &s1, string &s2){
    if (j<0) return i+1;
    if (i<0) return j+1;

    if (s1[i] == s2[j]) return solve1(i-1, j-1, s1, s2);
    
    int ins = solve1(i, j-1, s1, s2);
    int del = solve1(i-1, j, s1, s2);
    int rep = solve1(i-1, j-1, s1, s2);

    return 1 + min(ins, min(del, rep));
}

int minDistance1(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    return solve1(n-1, m-1, s1, s2);
}

// Memoization
int solve2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if (j == 0) return i;
    if (i == 0) return j;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i-1] == s2[j-1]) return dp[i][j] = solve2(i-1, j-1, s1, s2, dp);
    
    int ins = solve2(i, j-1, s1, s2, dp);
    int del = solve2(i-1, j, s1, s2, dp);
    int rep = solve2(i-1, j-1, s1, s2, dp);

    return dp[i][j] = 1 + min(ins, min(del, rep));
}

int minDistance2(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    return solve2(n, m, s1, s2, dp);
}

// Tabulation
int minDistance3(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i=0; i<=n; i++) dp[i][0] = i;
    for (int j=0; j<=m; j++) dp[0][j] = j;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                int ins = dp[i][j-1];
                int del = dp[i-1][j];
                int rep = dp[i-1][j-1];

                dp[i][j] = 1 + min(ins, min(del, rep));
            }
        }
    }

    return dp[n][m];
}

// Space Optimization
int minDistance(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> prev(m+1, 0), cur(m+1, 0);

    // for (int i=0; i<=n; i++) dp[i][0] = i;
    for (int j=0; j<=m; j++) prev[j] = j;

    for (int i=1; i<=n; i++){
        cur[0] = i;
        for (int j=1; j<=m; j++){
            if (s1[i-1] == s2[j-1])
                cur[j] = prev[j-1];
            else {
                int ins = cur[j-1];
                int del = prev[j];
                int rep = prev[j-1];

                cur[j] = 1 + min(ins, min(del, rep));
            }
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