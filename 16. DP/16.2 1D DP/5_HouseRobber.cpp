#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &nums, vector<int> &dp){
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + solve(ind-2, nums, dp);
    int notPick = 0 + solve(ind-1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int helper (vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i=1; i<n; i++) {
        int pick = i>1 ? nums[i] + dp[i-2] : nums[i];
        int notPick = 0 + dp[i-1];

        dp[i] = max(pick, notPick);
    }

    return dp[n-1];

}

int helper2(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i=1; i<n ;i++) {
        int pick = i>1 ? nums[i]+prev2 : nums[i];
        int notPick = 0 + prev;

        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp1(n+1, -1), dp2(n+1, -1);

    vector<int> temp1, temp2;
    for (int i=0; i<n; i++){
        if (i!=0) temp1.push_back(nums[i]);
        if (i!=n-1) temp2.push_back(nums[i]);
    }

    return max(helper2(temp1), helper2(temp2));
    // return max(solve(n-2, temp1, dp1), solve(n-2, temp2, dp2));
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}