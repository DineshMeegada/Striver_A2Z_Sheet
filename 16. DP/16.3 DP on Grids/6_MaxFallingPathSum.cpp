#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int row, int col, vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    if (col<0 || col>=m) return -1e9;
    if (row == 0) return matrix[row][col];

    int up_l = solve1(row-1, col-1, matrix);
    int up = solve1(row-1, col, matrix);
    int up_r = solve1(row-1, col+1, matrix);

    return matrix[row][col] + max(up, max(up_l, up_r));

}

int maxFallingPath1(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int max_sum = 0;
    for (int k=0; k<m; k++){
        max_sum = max(max_sum, solve1(m-1, k, matrix));
    }

    return max_sum;
}

// Memoization
int solve2(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    int n = matrix.size(), m = matrix[0].size();
    if (col<0 || col>=m) return -1e9;
    if (row == 0) return matrix[row][col];

    int up_l = matrix[row][col] + solve2(row-1, col-1, matrix, dp);
    int up = matrix[row][col] + solve2(row-1, col, matrix, dp);
    int up_r = matrix[row][col] + solve2(row-1, col+1, matrix, dp);

    return dp[row][col] = max(up, max(up_l, up_r));
}

int maxFallingPath2(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int max_sum = -1e9;
    for(int k=0; k<m; k++){
        max_sum = max(max_sum, solve2(n-1, k, matrix, dp));
    }

    return max_sum;
}

// Tabulation

int maxFallingPath3(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i=0; i<m; i++){
        dp[0][i] = matrix[0][i];
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<m; j++){
            int left = j==0 ? INT_MIN : dp[i-1][j-1];
            int right = j==m-1 ? INT_MIN : dp[i-1][j+1];
            dp[i][j] = matrix[i][j] + max(dp[i-1][j], max(left, right));
        }
    }

    int max_sum = -1e9;
    for (int j=0; j<m; j++){
        max_sum = max(max_sum, dp[n-1][j]);
    }

    return max_sum;
}

// Space Optimization
int maxFallingPath4(vector<vector<int>> &matrix){
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m), cur(m);

    for (int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<m; j++){
            int left = j==0 ? -1e9 : prev[j-1];
            int right = j==m-1 ? -1e9 : prev[j+1];
            cur[j] = matrix[i][j] + max(prev[j], max(left, right));
        }
        prev = cur;
    }

    int max_sum = -1e9;
    for (int i=0; i<m; i++){
        max_sum = max(max_sum, prev[i]);
    }

    return max_sum;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> matrix[i][j] ;
        }
    }

    cout << maxFallingPath1(matrix);
    
    
    
    return 0;
}