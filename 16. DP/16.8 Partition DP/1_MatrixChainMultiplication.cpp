#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int min_steps = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j];
        steps += solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);

        min_steps = min(min_steps, steps);
    }

    return dp[i][j] = min_steps;
}

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solve(1, n - 1, arr, dp);
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

    cout << matrixMultiplication(arr) << endl;

    return 0;
}