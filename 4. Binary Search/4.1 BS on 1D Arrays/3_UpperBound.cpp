#include <bits/stdc++.h>
using namespace std;

// Smallest index such that arr[ind] > x
int upperBound(vector<int> arr, int n, int k) {
    int low = 0, high = n-1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > k) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int upBound = upperBound(arr, n, k);
    cout << upBound;
    
    return 0;
}