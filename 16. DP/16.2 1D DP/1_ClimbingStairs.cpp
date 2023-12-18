#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int ind, vector<int> &dp){
    if (ind<=1) return 1;
    if (dp[ind] != -1) return dp[ind];

    int left = solve(ind-1, dp);
    int right = solve(ind-2, dp);

    return dp[ind] = left + right;
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

// Tabulation
int climbStairs2(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Space Optimization
int climbStairs3(int n){
    if (n <= 1) return 1;

    int prev = 1, prev2 = 1;
    for (int i=2; i<=n; i++){
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    cout << climbStairs3(n);
    
    
    return 0;
}