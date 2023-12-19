#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, vector<int> &nums){
    if (ind <= 1) return nums[ind];

    int cur1 = solve(ind-2, nums);
    int cur2 = ind>2 ? solve(ind-3, nums) : INT_MIN;

    return max(cur1, cur2) + nums[ind];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans1 = solve(n-1, nums);
    int ans2 = n>1 ? solve(n-2, nums) : INT_MIN;

    return max(ans1, ans2);
}

// Memoization
int solve2(int ind, vector<int> &nums, vector<int> &dp){
    if (ind <= 1) return nums[ind];
    if (dp[ind] != -1) return dp[ind];

    int cur1 = solve2(ind-2, nums, dp);
    int cur2 = ind>2 ? solve2(ind-3, nums, dp) : INT_MIN;

    return dp[ind] = max(cur1, cur2) + nums[ind];
}

int maximumNonAdjacentSum2(vector<int> &nums){
    int n = nums.size();
    vector<int> dp1(n, -1), dp2(n, -1);
    int ans1 = solve2(n-1, nums, dp1);
    int ans2 = n>1 ? solve2(n-2, nums, dp2) : INT_MIN;

    return max(ans1, ans2);
}

// Tabulation
int maximumNonAdjacentSum3(vector<int> &nums){
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = dp[0] + nums[2];

    for (int i=3; i<n; i++){
        dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
    }

    return max(dp[n-1], dp[n-2]);

}

// Space Optimization
int maximumNonAdjacentSum4(vector<int> &nums){
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = n>=2 ? nums[1] : INT_MIN;
    int prev3 = n>=3 ? nums[0]+nums[2] : nums[0];

    for (int i=3; i<n; i++){
        int cur = max(prev1, prev2) + nums[i];

        prev1 = prev2;
        prev2 = prev3;
        prev3 = cur;
    }

    return max(prev2, prev3);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << maximumNonAdjacentSum4(arr);
    
    
    
    return 0;
}