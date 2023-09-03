#include <bits/stdc++.h>
using namespace std;

int trapBetter(vector<int>& height) {
    int n = height.size();

    vector<int> prev(n);
    int prev_max = 0;
    for (int i=0; i<n; i++) {
        prev_max = max(prev_max, height[i]);
        prev[i] = prev_max;
    }

    vector<int> after(n);
    int after_max = 0;
    for (int i=n-1; i>=0; i--) {
        after_max = max(after_max, height[i]);
        after[i] = after_max;
    }

    int water = 0;
    for (int i=0; i<n; i++) {
        int curr = min(prev[i], after[i]) - height[i];
        water += curr;
    }

    return water;
}

int trap(vector<int> &height) {
    int n = height.size();

    int left_max = 0, right_max = 0;
    int left = 0, right = n-1;

    int water = 0;
    while (left < right) {
        if (height[left] <= height[right]){
            if (left_max <= height[left]) left_max = height[left];
            else water += left_max-height[left];
            left++;
        }else {
            if (right_max <= height[right]) right_max = height[right];
            else water += right_max - height[right];
            right--;
        }
    }

    return water;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int water = trap(arr);
    cout << water;

    
    return 0;
}