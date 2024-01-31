#include <bits/stdc++.h>
using namespace std;

// Memoization
bool solve1(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if (target==0) return true;
    if (ind==0) return target==arr[0];

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTaken = solve1(ind-1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target) taken = solve1(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference1(vector<int>& nums, int n){
    int sum = 0;
    for (auto it: nums) sum += it;

    vector<vector<int>> dp(n, vector<int>(sum+1, -1)); 

    for (int i=0; i<=sum; i++){
        bool dummy = solve1(n-1, i, nums, dp);
    }

    int ans = 1e9;
    for (int i=0; i<=sum/2; i++){
        int s1 = i, s2 = sum-i;
        if (dp[n-1][s1]) ans = min(ans, abs(s1-s2));
    }

    return ans;
}

// Space Optimization
vector<bool> solve3(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1, false);
    // unordered_map<int, bool> prev;
    prev[0] = true;
    prev[arr[0]] = true;

    for(int ind=1; ind<n; ind++){
        vector<bool> cur(k+1, false);
        // unordered_map<int, bool> cur;
        cur[0] = true;
        for (int target=1; target<=k; target++){
            int notPick = prev[target];
            int pick = false;
            if (arr[ind] <= target) pick = prev[target-arr[ind]];

            cur[target] = pick || notPick;
        }

        prev = cur;
    }

    return prev;
}

int minSubsetSumDifference3(vector<int>& nums, int n){
    int sum = 0;
    for (auto it: nums) sum += it;

    vector<bool> isPos = solve3(n, sum, nums);
    // for (auto it: isPos) cout << it.first << " -> " << it.second << endl;

    int ans = 1e9;
    for (int i=0; i<=sum/2; i++){
        int s1 = i, s2 = sum-i;
        if (isPos[s1]) ans = min(ans, abs(s1-s2));
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}