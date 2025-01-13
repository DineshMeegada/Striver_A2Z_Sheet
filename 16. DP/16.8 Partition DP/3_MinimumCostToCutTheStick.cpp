#include <bits/stdc++.h>
using namespace std;

// Memoization Approach
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int min_val = 1e9, cost = cuts[j + 1] - cuts[i - 1];
    for (int ind = i; ind <= j; ind++)
    {
        int cur = solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp);
        min_val = min(min_val, cur + cost);
    }

    return dp[i][j] = min_val;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    int ans = solve(1, c, cuts, dp);
    return ans;
}

// Tabulation Approach
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i > 0; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int min_val = 1e9, cost = cuts[j + 1] - cuts[i - 1];
            for (int ind = i; ind <= j; ind++)
            {
                int cur = dp[i][ind - 1] + dp[ind + 1][j];
                min_val = min(min_val, cur + cost);
            }

            dp[i][j] = min_val;
        }
    }

    int ans = dp[1][c];
    return ans;
}

int main()
{
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> cuts(n);
    for (int i = 0; i < n; i++)
        cin >> cuts[i];

    cout << minCost(n, cuts);

    return 0;
}