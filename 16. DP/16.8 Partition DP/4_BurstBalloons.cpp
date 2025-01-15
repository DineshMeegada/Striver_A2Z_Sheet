#include <bits/stdc++.h>
using namespace std;

// Memoization Approach
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int max_coins = -1e9;
    for (int k = i; k <= j; k++)
    {
        int coins = arr[i - 1] * arr[k] * arr[j + 1];
        coins += solve(i, k - 1, arr, dp) + solve(k + 1, j, arr, dp);
        max_coins = max(max_coins, coins);
    }

    return dp[i][j] = max_coins;
}

int maxCoins1(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solve(1, n, nums, dp);
    return ans;
}

// Tabulation Approach
int maxCoins(vector<int> &arr)
{
    int n = arr.size();
    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int max_coins = -1e9;
            for (int k = i; k <= j; k++)
            {
                int coins = arr[i - 1] * arr[k] * arr[j + 1];
                coins += dp[i][k - 1] + dp[k + 1][j];
                max_coins = max(max_coins, coins);
            }

            dp[i][j] = max_coins;
        }
    }

    int ans = dp[1][n];
    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxCoins(arr) << endl;

    return 0;
}