#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> hash(n), dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                hash[i] = prev;
                dp[i] = 1 + dp[prev];
            }
        }
    }

    int cnt = 0, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > cnt)
        {
            cnt = dp[i];
            ind = i;
        }
    }

    vector<int> ans;
    while (hash[ind] != ind)
    {
        ans.push_back(nums[ind]);
        ind = hash[ind];
    }
    ans.push_back(nums[ind]);

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = largestDivisibleSubset(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}