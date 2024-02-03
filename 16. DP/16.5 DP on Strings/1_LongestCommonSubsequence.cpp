#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int ind1, int ind2, string text1, string text2){
    if (ind1<0 || ind2<0) return 0;

    if (text1[ind1] == text2[ind2]) 
        return 1 + solve1(ind1-1, ind2-1, text1, text2);
    
    return max(solve1(ind1-1, ind2, text1, text2), solve1(ind1, ind2-1, text1, text2));
}

int longestCommonSubsequence1(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    return solve1(n-1, m-1, text1, text2);
}

// Memoization
int solve2(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
    if (ind1==0 || ind2==0) return 0;
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if (text1[ind1-1] == text2[ind2-1]) 
        return dp[ind1][ind2] = 1 + solve2(ind1-1, ind2-1, text1, text2, dp);
    
    return dp[ind1][ind2] = max(solve2(ind1-1, ind2, text1, text2, dp), solve2(ind1, ind2-1, text1, text2, dp));
}

int longestCommonSubsequence2(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solve2(n, m, text1, text2, dp);
}

// Tabulation
int longestCommonSubsequence3(string text1, string text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int ind1=1; ind1<=n; ind1++){
        for (int ind2=1; ind2<=m; ind2++){
            if(text1[ind1-1] == text2[ind2-1]) 
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else 
                dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }

    return dp[n][m];
}

// Space Optimization
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<int> prev(m+1, 0);
    // for (int j=0; j<=m; j++) dp[0][j] = 0;
    // for (int i=0; i<=n; i++) dp[i][0] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++) {
        vector<int> cur(m+1, 0);
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (text1[ind1 - 1] == text2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] =
                    max(prev[ind2], cur[ind2 - 1]);
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