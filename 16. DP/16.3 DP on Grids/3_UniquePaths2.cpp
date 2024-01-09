#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int row, int col, vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    if (row<0 || row>=n || col<0 || col>=m) return 0;
    if (grid[row][col] == 1) return 0;
    if (row==n-1 && col==m-1) return 1;

    int right = solve(row, col+1, grid);
    int down = solve(row+1, col, grid);

    return right+down;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    return solve(0,0,obstacleGrid);
}

// Memoization
int solve2(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
    int n = grid.size(), m = grid[0].size();
    if (row<0 || row>=n || col<0 || col>=m) return 0;
    if (grid[row][col] == 1) return 0;
    if (row==n-1 && col==m-1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int right = solve2(row, col+1, grid, dp);
    int down = solve2(row+1, col, grid, dp);

    return dp[row][col] = right+down;
}

int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve2(0,0,obstacleGrid, dp);
}

// Tabulation
int uniquePathsWithObstacles3(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (i==0 && j==0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i>0) up = dp[i-1][j];
            if (j>0) left = dp[i][j-1];

            dp[i][j] = up+left;
        }
    }

    return dp[n-1][m-1];
}

// Space Optimization
int uniquePathsWithObstacles4(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m);

    for (int i=0; i<n; i++){
        vector<int> cur(m);
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1) {
                cur[j] = 0;
                continue;
            }
            if (i==0 && j==0) {
                cur[j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i>0) up = dp[j];
            if (j>0) left = cur[j-1];

            cur[j] = up+left;
        }

        dp = cur;
    }

    return dp[m-1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}