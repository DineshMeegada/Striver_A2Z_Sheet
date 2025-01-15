#include <bits/stdc++.h>
using namespace std;

// Memoization Approach
int solve(int ind, int k, vector<int> &arr, vector<int> &dp)
{
    int n = arr.size();
    if (ind >= n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int maxVal = -1e9, res = -1e9;
    for (int i = ind; i < min(n, ind + k); i++)
    {
        maxVal = max(maxVal, arr[i]);
        int cur = (maxVal * (i - ind + 1)) + solve(i + 1, k, arr, dp);
        res = max(res, cur);
    }

    return dp[ind] = res;
}

int maxSumAfterPartitioning1(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);

    int ans = solve(0, k, arr, dp);
    return ans;
}

// Tabulation Approach
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int maxVal = -1e9, res = -1e9;
        for (int i = ind; i < min(n, ind + k); i++)
        {
            maxVal = max(maxVal, arr[i]);
            int cur = (maxVal * (i - ind + 1)) + dp[i + 1];
            res = max(res, cur);
        }

        dp[ind] = res;
    }

    int ans = dp[0];
    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSumAfterPartitioning(arr, k);

    return 0;
}