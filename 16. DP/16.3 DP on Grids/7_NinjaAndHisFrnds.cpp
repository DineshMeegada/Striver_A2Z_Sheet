#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int row, int col1, int col2, int m, int n, vector<vector<int>> &grid){
    if (col1<0 || col2<0 || col1>=m || col2>=m) return -1e9;
    if (row == n-1){
        if (col1==col2) return grid[row][col1];
        else return grid[row][col1] + grid[row][col2];
    }

    int ans = -1e9;
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int cur;
            if (col1==col2) cur = grid[row][col1] + solve1(row+1, col1+i, col2+j, m, n, grid);
            else cur = grid[row][col1] + grid[row][col2] + solve1(row+1, col1+i, col2+j, m, n, grid);
            ans = max(ans, cur);
        }
    }

    return ans;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    return solve1(0, 0, m-1, m, n, grid);
}

// Memoization
int solve1(int row, int col1, int col2, int m, int n, vector<vector<int>> &grid,
            vector<vector<vector<int>>> &dp){
    if (col1<0 || col2<0 || col1>=m || col2>=m) return -1e9;
    if (row == n-1){
        if (col1==col2) return grid[row][col1];
        else return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

    int ans = -1e9;
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int cur;
            if (col1==col2) cur = grid[row][col1] + solve1(row+1, col1+i, col2+j, m, n, grid, dp);
            else cur = grid[row][col1] + grid[row][col2] + solve1(row+1, col1+i, col2+j, m, n, grid, dp);
            ans = max(ans, cur);
        }
    }

    return dp[row][col1][col2] = ans;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve1(0, 0, m-1, m, n, grid, dp);
}

// Tabulation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
    for (int j1=0; j1<m; j1++){
        for (int j2=0; j2<m; j2++) {
            if (j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
        }
    }

    for (int i=n-2; i>=0; i--){
        for (int j1=0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){

                int ans = -1e8;
                for (int dj1=-1; dj1<=1; dj1++){
                    for (int dj2=-1; dj2<=1; dj2++){
                        int cur;
                        if (j1==j2) cur = grid[i][j1];
                        else cur = grid[i][j1]+grid[i][j2];

                        if ((j1+dj1<0 || j1+dj1>=m) || (j2+dj2<0 || j2+dj2>=m))
                            cur += -1e9;
                        else cur += dp[i+1][j1+dj1][j2+dj2];

                        ans = max(ans, cur);
                    }
                }

                dp[i][j1][j2] = ans;
            }
        }
    }

    return dp[0][0][m-1];

}

// Space Optimization
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> front(m, vector<int>(m)), temp(m, vector<int>(m));
    
    for (int j1=0; j1<m; j1++){
        for (int j2=0; j2<m; j2++) {
            if (j1==j2) front[j1][j2] = grid[n-1][j1];
            else front[j1][j2] = grid[n-1][j1]+grid[n-1][j2];
        }
    }

    for (int i=n-2; i>=0; i--){
        for (int j1=0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){

                int ans = -1e8;
                for (int dj1=-1; dj1<=1; dj1++){
                    for (int dj2=-1; dj2<=1; dj2++){
                        int cur;
                        if (j1==j2) cur = grid[i][j1];
                        else cur = grid[i][j1]+grid[i][j2];

                        if ((j1+dj1<0 || j1+dj1>=m) || (j2+dj2<0 || j2+dj2>=m))
                            cur += -1e9;
                        else cur += front[j1+dj1][j2+dj2];

                        ans = max(ans, cur);
                    }
                }

                temp[j1][j2] = ans;
            }
        }

        front = temp;
    }

    return front[0][m-1];

}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}