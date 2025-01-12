#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size(), maxLen = 1;
    vector<int> dp(n, 1), count(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                if (dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];
                }
                else if (dp[i] == 1 + dp[prev])
                    count[i] += count[prev];
            }
        }

        maxLen = max(maxLen, dp[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
            cnt += count[i];
    }

    return cnt;
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

    int ans = findNumberOfLIS(arr);
    cout << ans;

    return 0;
}