#include <bits/stdc++.h>
using namespace std;

int KthMissingNum(vector<int> arr, int n, int k){
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        int miss_count = arr[mid]-mid-1;
        if (miss_count >= k) high = mid - 1;
        else low = mid + 1;

        // cout << low << " " << high << " " << miss_count << endl;
    }

    if (high < 0) return k;

    int rem_count = k - arr[high] + high + 1;
    return (arr[high] + rem_count);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    int num = KthMissingNum(arr, n, k);
    cout << num ;
    
    
    return 0;
}