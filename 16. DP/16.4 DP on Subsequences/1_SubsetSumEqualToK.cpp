#include <bits/stdc++.h>
using namespace std;

// Recursion
bool solve1(int ind, int target, vector<int>& arr){
    if (target==0) return true;
    if (ind==0) return arr[0]==target;

    bool notTake = solve1(ind-1, target, arr);
    bool take = false;
    if (arr[ind]<= target) take = solve1(ind-1, target-arr[ind], arr);

    return take | notTake;
    
}

bool subsetSumToK1(int n, int k, vector<int> &arr) {
    return solve1(n-1, k, arr);    
}

// Memoization
bool solve2(int ind, int target, vector<int>& arr, vector<vector<int>> dp){
    if (target==0) return true;
    if (ind==0) return arr[0]==target;

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTake = solve2(ind-1, target, arr, dp);
    bool take = false;
    if (arr[ind]<= target) take = solve2(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take | notTake;
    
}

bool subsetSumToK2(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve2(n-1, k, arr, dp);    
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for (int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0]<=k) dp[0][arr[0]] = true;
    
    for (int ind=1; ind<n; ind++){
        for (int target=1; target<=k; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];

            dp[ind][target] = take || notTake;

        }
    }

    return dp[n-1][k];
}

// Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    prev[0] = true;
    if(arr[0]<=k) prev[arr[0]] = true;
    
    for (int ind=1; ind<n; ind++){
        vector<bool> cur(k+1, false);
        cur[0] = true;
        for (int target=1; target<=k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind]<=target) take = prev[target-arr[ind]];

            cur[target] = take || notTake;
        }

        prev = cur;
    }

    return prev[k];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}