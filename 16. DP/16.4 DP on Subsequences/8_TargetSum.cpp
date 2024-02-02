#include <bits/stdc++.h>
using namespace std;

// It is just same as 5_PartitionsWithGivenDiff problem
// Just asked in a different format

int findWays(vector<int> &nums, int tar){
    int n = nums.size();
    
    vector<int> prev(tar+1, 0);
    if (nums[0]==0) prev[0] = 2;
    else prev[0] = 1;

    if (nums[0]!=0 && nums[0]<=tar) prev[nums[0]] = 1;

    for (int ind=1; ind<n; ind++){
        vector<int> cur(tar+1, 0);
        for (int sum=0; sum<=tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if (nums[ind]<=sum) take = prev[sum-nums[ind]];

            cur[sum] = take+notTake;
        }
        
        prev = cur;
    }

    return prev[tar];
}

int findTargetSumWays(vector<int>& nums, int d) {
    int n = nums.size();

    int sum = 0;
    for (auto it: nums) sum += it;

    if (sum-d<0 || (sum-d)%2==1) return 0;
    return findWays(nums, (sum-d)/2);

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}