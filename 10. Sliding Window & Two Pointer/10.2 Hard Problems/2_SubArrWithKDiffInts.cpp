#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> s, int k){
    int n = s.size();
    int left = 0;
    unordered_map<int, int> freq;
    int ans = 0;

    for (int right=0; right<n; right++) {
        freq[s[right]]++;
        while (freq.size() > k){
            freq[s[left]]--;
            if (freq[s[left]]==0) freq.erase(s[left]);
            left++;
        }

        ans += right-left+1;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums, k) - helper(nums, k-1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int count = subarraysWithKDistinct(arr, k);
    cout << count;

    
    return 0;
}