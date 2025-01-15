#include <bits/stdc++.h>
using namespace std;

// Memoization Approach
bool isPalindrome(int start, int end, string &s)
{
    for (int i = start; i <= (start + end) / 2; i++)
    {
        if (s[i] != s[end - (i - start)])
            return false;
    }
    return true;
}

int solve(int ind, int n, string &s, vector<int> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int min_cuts = 1e9;
    for (int i = ind; i < n; i++)
    {
        if (isPalindrome(ind, i, s))
        {
            int cuts = 1 + solve(i + 1, n, s, dp);
            min_cuts = min(min_cuts, cuts);
        }
    }

    return dp[ind] = min_cuts;
}

int minCut1(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);

    int ans = solve(0, n, s, dp) - 1;
    return ans;
}

// Tabulation Approach
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int min_cuts = 1e9;
        for (int i = ind; i < n; i++)
        {
            if (isPalindrome(ind, i, s))
            {
                int cuts = 1 + dp[i + 1];
                min_cuts = min(min_cuts, cuts);
            }
        }

        dp[ind] = min_cuts;
    }

    int ans = dp[0] - 1;
    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << minCut(s);

    return 0;
}