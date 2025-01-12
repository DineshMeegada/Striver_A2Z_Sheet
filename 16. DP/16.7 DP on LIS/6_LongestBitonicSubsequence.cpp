#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums)
{
    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int aft = i + 1; aft < n; aft++)
        {
            if (nums[i] > nums[aft])
                dp2[i] = max(dp2[i], 1 + dp2[aft]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp1[i] == 1 || dp2[i] == 1)
            continue;
        int cur = dp1[i] + dp2[i] - 1;
        ans = max(ans, cur);
    }

    return ans;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << LongestBitonicSequence(n, nums);

    return 0;
}