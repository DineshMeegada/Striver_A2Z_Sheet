#include <bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();

    stack<int> minStack;
    minStack.push(-1);
    long long minSum = 0;
    for (int i=0; i<=n; i++) {

        while (minStack.top()!=-1 && (i==n || nums[minStack.top()]>=nums[i])) {
            int mid = minStack.top();
            minStack.pop();

            int range = (mid-minStack.top())*(i-mid);
            minSum += range*nums[mid];
        }

        minStack.push(i);
    }

    stack<int> maxStack;
    maxStack.push(-1);
    long long maxSum = 0;
    for (int i=0; i<=n; i++) {

        while (maxStack.top()!=-1 && (i==n || nums[maxStack.top()]<=nums[i])) {
            int mid = maxStack.top();
            maxStack.pop();

            int range = (mid-maxStack.top())*(i-mid);
            maxSum += range*nums[mid];
        }

        maxStack.push(i);
    }

    return maxSum-minSum;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    long long res = subArrayRanges(arr);
    cout << res;

    
    return 0;
}