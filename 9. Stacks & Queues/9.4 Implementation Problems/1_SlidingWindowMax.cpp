#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> res;

    for (int i=0; i<n; i++) {
        while (dq.size() && dq.front()<=i-k) dq.pop_front();

        while (dq.size() && nums[dq.back()]<nums[i]) dq.pop_back();
        dq.push_back(i);

        if (i>=k-1) res.push_back(nums[dq.front()]);
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
    
    vector<int> res = maxSlidingWindow(arr, k);
    for (auto it: res) cout << it << ' ';

    
    return 0;
}