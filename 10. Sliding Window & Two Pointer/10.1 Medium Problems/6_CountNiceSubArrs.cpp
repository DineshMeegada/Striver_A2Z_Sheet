#include <bits/stdc++.h>
using namespace std;

int Atmost(vector<int> nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int cnt = 0, res = 0;
    
    while (right<n && left<=right) {
        cnt += nums[right]%2;
        while (cnt>k){
            cnt -= nums[left++]%2;
        }
        res += right++ - left + 1;
    }

    return res;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return Atmost(nums, k) - Atmost(nums, k-1);
}

int numberOfSubarraysOpt(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0, cnt = 0, odd = 0;
    int left = 0;

    for (int right=0; right<n; right++) {
        if (nums[right]&1) {
            odd++;
            cnt = 0;
        }

        while (odd == k) {
            cnt++;
            odd -= nums[left++]&1;
        }

        res += cnt;
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int count = numberOfSubarrays(arr, k);
    cout << count;

    
    return 0;
}