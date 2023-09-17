#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = 0;
    int res = 0;

    while (r < n-1) {
        int farthest = 0;
        for (int i=l; i<=r; i++) {
            farthest = max(farthest, i+nums[i]);
        }

        l = r+1;
        r = farthest;
        res++;
        if (res > 4) return 0;
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << jump(arr);



    return 0;
}