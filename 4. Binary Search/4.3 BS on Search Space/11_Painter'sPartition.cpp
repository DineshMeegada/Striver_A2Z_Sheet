#include <bits/stdc++.h>
using namespace std;

bool isPossible (vector<int> arr, int paint, int k) {
    int painters = 1, curr_paint = 0;
    for (int i=0; i<arr.size(); i++) {
        if (arr[i]>paint) return false;
        if (curr_paint + arr[i] <= paint) curr_paint += arr[i];
        else {
            painters++;
            curr_paint = arr[i];
        }
    } 

    // cout << paint << " " << painters << endl;

    return (painters <= k);
}

int painter_partition(vector<int> arr, int n, int k) {
    int low = INT_MAX, high = 0;

    for (int i=0; i<n; i++) {
        low = min(low, arr[i]);
        high += arr[i];
    }


    while (low <= high) {
        int mid = low + (high - low) / 2;

        // cout << low << " " << mid << " " << high << endl;

        if (isPossible(arr, mid, k)) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;

    for(int a=0; a<t; a++){
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];

        int part = painter_partition(arr, n, k);
        cout << part << endl;
    }
    
    return 0;
}