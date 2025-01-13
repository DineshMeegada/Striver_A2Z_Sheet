#include <bits/stdc++.h>
using namespace std;

// Tabulation
int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int min_steps = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j];
                steps += dp[i][k] + dp[k + 1][j];

                min_steps = min(min_steps, steps);
            }

            dp[i][j] = min_steps;
        }
    }

    int ans = dp[1][n - 1];
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