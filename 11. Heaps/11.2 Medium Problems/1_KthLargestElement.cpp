#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;

    for (int it: nums) pq.push(it);
    while (--k) pq.pop();

    return pq.top();
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int num = findKthLargest(arr, k);
    cout << num ;

    
    return 0;
}