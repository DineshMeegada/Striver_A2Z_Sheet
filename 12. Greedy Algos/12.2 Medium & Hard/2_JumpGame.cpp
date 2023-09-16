#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int goal = n-1;
    for (int i=n-2; i>=0; i--) {
        if (i + nums[i] >= goal) goal = i;
    }

    return goal == 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << canJump(arr);

    
    return 0;
}