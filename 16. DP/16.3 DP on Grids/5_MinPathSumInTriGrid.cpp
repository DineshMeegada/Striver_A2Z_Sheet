#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int row, int col, vector<vector<int>> &triangle){
    int n = triangle.size();
    if (row == n-1) return triangle[row][col];

    int down = solve1(row+1, col, triangle);
    int diagnol = solve1(row+1, col+1, triangle);

    return triangle[row][col] + min(down, diagnol);
}

int minimumTotal1(vector<vector<int>>& triangle) {
    return solve1(0, 0, triangle);
}

// Memoization
int solve2(int row, int col, vector<vector<int>> &tri, vector<vector<int>> &dp){
    int n = tri.size();
    if (row == n-1) return tri[row][col];
    if (dp[row][col] != -1) return dp[row][col];

    int down = solve2(row+1, col, tri, dp);
    int diag = solve2(row+1, col+1, tri, dp);

    return dp[row][col] = tri[row][col] + min(down, diag);
}

int minimumTotal2(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve2(0, 0, triangle, dp);
}

// Tabulation
int minimumTotal3(vector<vector<int>> &tri){
    int n = tri.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i=0; i<n; i++){
        dp[n-1][i] = tri[n-1][i];
    }

    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            dp[i][j] = tri[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}

// Space Optimization
int minimumTotal4(vector<vector<int>> &tri){
    int n = tri.size();
    vector<int> dp(n, -1);

    for (int i=0; i<n; i++){
        dp[i] = tri[n-1][i];
    }

    for (int i=n-2; i>=0; i--){
        vector<int> temp(i+1);
        for (int j=0; j<=i; j++){
            temp[j] = tri[i][j] + min(dp[j], dp[j+1]);
        }
        dp = temp;
    }

    return dp[0];

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n ;

    vector<vector<int>> triangle(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++) cin >> triangle[i][j];
    }

    int total = minimumTotal3(triangle);
    cout << total;
    
    
    return 0;
}