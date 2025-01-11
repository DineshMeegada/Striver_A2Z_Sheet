#include <bits/stdc++.h>
using namespace std;

int low_bound(int target, vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;

    for (int num : nums)
    {
        int ind = low_bound(num, temp);

        if (ind >= temp.size())
            temp.push_back(num);
        else
            temp[ind] = num;
    }

    return temp.size();
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

    cout << lengthOfLIS(nums);

    return 0;
}