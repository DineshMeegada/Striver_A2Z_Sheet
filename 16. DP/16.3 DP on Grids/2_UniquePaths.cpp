#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int row, int col){
    if (row==0 && col==0) return 1;
    if (row<0 || col<0) return 0;

    int up = solve(row-1, col);
    int left = solve(row, col-1);

    return up+left;
}

int uniquePaths(int m, int n) {
    return solve(m-1, n-1);
}


// Memoization
int solve2(int row, int col, vector<vector<int>> &dp){
    if (row==0 && col==0) return 1;
    if (row<0 || col<0) return 0;
    if (dp[row][col] != -1) return dp[row][col];

    int up = solve2(row-1, col, dp);
    int left = solve2(row, col-1, dp);

    return dp[row][col] = up+left;
}

int uniquePaths2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve2(m-1, n-1, dp);
}

// Tabulation
int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m, n, dp);
}

// Space Optimization
int uniquePaths(int m, int n) {
    vector<int> prev(n);
    for (int i=0; i<m; i++){
        vector<int> dp(n);
        for (int j=0; j<n; j++){
            if (i==0 && j==0) {
                dp[j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i>0) up = prev[j];
            if (j>0) left = dp[j-1];

            dp[j] = up+left; 
        }

        prev = dp;
    }

    return prev[n-1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;


    
    
    
    return 0;
}