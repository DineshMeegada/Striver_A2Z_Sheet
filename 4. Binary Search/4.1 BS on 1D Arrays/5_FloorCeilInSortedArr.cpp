#include <bits/stdc++.h>
using namespace std;

pair<int, int> FloorAndCeil(vector<int> arr, int n, int k) {
    int low = 0, high = n-1;
    int floor = -1, ceil = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] <= k){
            floor = arr[mid];
            low = mid + 1;
        } else high = mid - 1;
    }

    int left = 0, right = n-1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= k){
            ceil = arr[mid];
            right = mid - 1;
        } else left = mid + 1;
    }

    return {floor, ceil};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    pair<int, int> limits = FloorAndCeil(arr, n, k);
    cout << limits.first << " " << limits.second;
    
    return 0;
}