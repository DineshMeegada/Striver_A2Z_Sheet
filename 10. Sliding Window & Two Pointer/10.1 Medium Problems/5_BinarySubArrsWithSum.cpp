#include <bits/stdc++.h>
using namespace std;

int Atmost(vector<int> nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0, res = 0;
    
    while (right<n && left<=right) {
        sum += nums[right];
        while (sum>k){
            sum -= nums[left++];
        }
        res += right++ - left + 1;
    }

    return res;
}

int numSubarraysWithSum(vector<int>& nums, int k) {
    return (Atmost(nums, k) - Atmost(nums, k-1));
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int count = numSubarraysWithSum(arr, k);
    cout << count;

    
    return 0;
}