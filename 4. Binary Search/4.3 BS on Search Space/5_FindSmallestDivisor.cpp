#include <bits/stdc++.h>
using namespace std;

long long int quotSum (vector<int> nums, int num) {
    long long int sum = 0;
    for (int i=0; i<nums.size(); i++){
        sum += (nums[i] + num - 1) / num;
    }

    return sum;
}

int smallestDivisor(vector<int> nums, int threshold) {
    int low = 1, high = 1e6;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long int sum = quotSum(nums, mid);

        if (sum <= threshold) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, threshold;
    cin >> n >> threshold;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int divisor = smallestDivisor(arr, threshold);
    cout << divisor;
    
    return 0;
}