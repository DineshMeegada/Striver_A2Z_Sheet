#include <bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    if (n != m + 1)
        return false;

    int i = 0, j = 0;
    while (i < n)
    {
        if (j < m && s1[i] == s2[j])
            j++;

        i++;
    }

    return i == n && j == m;
}

static bool comp(string &word1, string &word2)
{
    return word1.size() < word2.size();
}

// Memoization Approach
int solve(int ind, int prev, vector<string> &words, vector<vector<int>> &dp)
{
    int n = words.size();
    if (ind >= n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int notTake = solve(ind + 1, prev, words, dp);
    int take = 0;
    if (prev == -1 || compare(words[ind], words[prev]))
        take = 1 + solve(ind + 1, ind, words, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int longestStrChain1(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), comp);

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = solve(0, -1, words, dp);
    return ans;
}

// Tabulation Approach
int longestStrChain2(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || compare(words[ind], words[prev]))
                take = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev + 1] = max(take, notTake);
        }
    }

    int ans = dp[0][0];
    return ans;
}

// Space Optimization
int longestStrChain(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<int> cur(n + 1, 0), forw(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = forw[prev + 1];
            int take = 0;
            if (prev == -1 || compare(words[ind], words[prev]))
                take = 1 + forw[ind + 1];

            cur[prev + 1] = max(take, notTake);
        }
        forw = cur;
    }

    int ans = cur[0];
    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    cout << longestStrChain(words);

    return 0;
}