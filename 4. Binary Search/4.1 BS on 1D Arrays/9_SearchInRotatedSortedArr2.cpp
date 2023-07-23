#include <bits/stdc++.h>
using namespace std;

int SearchInRotatedSortedArr (vector<int> arr, int n, int k) {
    int low = 0, high = n-1;
    
    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] == k) return true;
        
        if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (arr[mid] <= k && k <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    bool index = SearchInRotatedSortedArr(arr, n, k);
    cout << index;
    
    
    return 0;
}