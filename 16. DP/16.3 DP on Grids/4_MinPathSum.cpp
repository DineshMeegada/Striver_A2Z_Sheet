#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int row, int col, vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    if(row<0 || row>=n || col<0 || col>=m) return INT_MAX;
    if (row==n-1 && col==m-1) return grid[row][col];

    int down = solve(row+1, col, grid);
    int right = solve(row, col+1, grid);

    return grid[row][col]+min(down, right);
}

int minPathSum(vector<vector<int>>& grid) {
    return solve(0, 0, grid);
}

// Memoization
int solve2(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
    int n = grid.size(), m = grid[0].size();
    if(row<0 || row>=n || col<0 || col>=m) return INT_MAX;
    if (row==n-1 && col==m-1) return grid[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    int down = solve2(row+1, col, grid, dp);
    int right = solve2(row, col+1, grid, dp);

    return dp[row][col] = grid[row][col]+min(down, right);
}

int minPathSum2(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve2(0, 0, grid, dp);
}

// Tabulation
int minPathSum3(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if (i>0) up = dp[i-1][j];
            if (j>0) left = dp[i][j-1];

            dp[i][j] = grid[i][j] + min(up, left);
        }
    }

    return dp[n-1][m-1];

}

// Space Optimization
int minPathSum4(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m);

    for (int i=0; i<n; i++){
        vector<int> dp(m);
        for (int j=0; j<m; j++){
            if (i==0 && j==0){
                dp[j] = grid[i][j];
                continue;
            } 

            int up = INT_MAX, left = INT_MAX;
            if (i>0) up = prev[j];
            if (j>0) left = dp[j-1];

            dp[j] = grid[i][j] + min(up, left);
        }
        prev = dp;
    }

    return prev[m-1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}