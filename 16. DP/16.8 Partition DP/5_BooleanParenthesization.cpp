#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1003;
// Memoization Approach

long long comparator(char comp, int lt, int lf, int rt, int rf, bool isTrue)
{
    if (comp == '&')
        return (isTrue) ? (lt * rt) % mod : (lf * rt + lt * rf + lf * rf) % mod;
    else if (comp == '|')
        return (isTrue) ? (lt * rt + lt * rf + lf * rt) % mod : (lf * rf) % mod;
    else if (comp == '^')
        return (isTrue) ? (lt * rf + lf * rt) % mod : (lt * rt + lf * rf) % mod;

    return 0;
}

int solve(int i, int j, bool isTrue, string &s, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return (isTrue) ? s[i] == 'T' : s[i] == 'F';
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int steps = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt = solve(i, k - 1, 1, s, dp);
        int lf = solve(i, k - 1, 0, s, dp);
        int rt = solve(k + 1, j, 1, s, dp);
        int rf = solve(k + 1, j, 0, s, dp);

        int cur = comparator(s[k], lt, lf, rt, rf, isTrue);
        steps = (steps + (cur) % mod) % mod;
    }

    return dp[i][j][isTrue] = steps;
}

int countWays1(int n, string s)
{
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    int ans = solve(0, n - 1, 1, s, dp);
    return ans;
}

// Tabulationn Approach
int countWays(int n, string s)
{
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i -= 2)
    {
        for (int j = i; j < n; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                if (i == j)
                {
                    dp[i][j][isTrue] = (isTrue) ? s[i] == 'T' : s[i] == 'F';
                    continue;
                }

                int steps = 0;
                for (int k = i + 1; k < j; k += 2)
                {
                    int lt = dp[i][k - 1][1];
                    int lf = dp[i][k - 1][0];
                    int rt = dp[k + 1][j][1];
                    int rf = dp[k + 1][j][0];

                    int cur = comparator(s[k], lt, lf, rt, rf, isTrue);
                    steps = (steps + (cur) % mod) % mod;
                }

                dp[i][j][isTrue] = steps;
            }
        }
    }

    int ans = dp[0][n - 1][1];
    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << countWays(n, s);

    return 0;
}