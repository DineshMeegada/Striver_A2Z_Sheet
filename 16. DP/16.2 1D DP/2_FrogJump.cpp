#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, vector<int> &heights){
    if (ind == 0) return 0;

    int left = solve(ind-1, heights)+abs(heights[ind]-heights[ind-1]);
    int right = ind>1 ? solve(ind-2, heights)+abs(heights[ind]-heights[ind-2]) : INT_MAX;

    return min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    return solve(n-1, heights);
}

// Memoization
int solve2(int ind, vector<int> &heights, vector<int> &dp){
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int left = solve2(ind-1, heights, dp)+abs(heights[ind]-heights[ind-1]);
    int right = ind>1 ? solve2(ind-2, heights, dp)+abs(heights[ind]-heights[ind-2]) : INT_MAX;

    return dp[ind] = min(left, right);
}

int frogJump2(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return solve2(n-1, heights, dp);
}

// Tabulation
int frogJump3(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);

    for (int i=2; i<n; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = dp[i-2] + abs(heights[i]- heights[i-2]);

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

// Space Optimization
int frogJump4(int n, vector<int> &heights){
    int prev = abs(heights[1]-heights[0]);
    int prev2 = 0;

    for (int i=2; i<n; i++){
        int left = prev + abs(heights[i]-heights[i-1]);
        int right = prev2 + abs(heights[i]- heights[i-2]);
        
        prev2 = prev;
        prev = min(left, right);
    }

    return prev;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << frogJump3(n, arr);
    
    
    
    return 0;
}