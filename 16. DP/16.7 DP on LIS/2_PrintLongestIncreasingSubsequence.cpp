#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> hash(n), dp(n, 1);
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
    }

    int cnt = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > cnt)
        {
            cnt = dp[i];
            index = i;
        }
    }

    vector<int> ans;
    while (hash[index] != index)
    {
        ans.push_back(arr[index]);
        index = hash[index];
    }
    ans.push_back(arr[index]);

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    return 0;
}