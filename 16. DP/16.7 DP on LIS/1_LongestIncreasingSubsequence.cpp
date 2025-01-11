#include <bits/stdc++.h>
using namespace std;

// Recursion Approach
int solve1(int ind, int prev, vector<int> &nums)
{
    int n = nums.size();
    if (ind >= n)
        return 0;

    int notTake = solve1(ind + 1, prev, nums);
    int take = 0;
    if (prev == -1 || nums[prev] < nums[ind])
        take = 1 + solve1(ind + 1, ind, nums);

    return max(take, notTake);
}

int lengthOfLIS1(vector<int> &nums)
{
    int n = nums.size();
    int ans = solve1(0, -1, nums);
    return ans;
}

// Memoization Approach
int solve2(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind >= n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int notTake = solve2(ind + 1, prev, nums, dp);
    int take = 0;
    if (prev == -1 || nums[prev] < nums[ind])
        take = 1 + solve2(ind + 1, ind, nums, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int lengthOfLIS2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = solve2(0, -1, nums, dp);
    return ans;
}

// Tabulation Approach
int lengthOfLIS3(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[prev] < nums[ind])
                take = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

// Space Optimization
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> cur(n + 1, 0), forw(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = forw[prev + 1];
            int take = 0;
            if (prev == -1 || nums[prev] < nums[ind])
                take = 1 + forw[ind + 1];

            cur[prev + 1] = max(take, notTake);
        }
        forw = cur;
    }

    return cur[0];
}

int main()
{
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    return 0;
}