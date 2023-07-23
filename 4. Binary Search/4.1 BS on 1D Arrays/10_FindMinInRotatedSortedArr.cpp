#include <bits/stdc++.h>
using namespace std;

int FindMinInRotatedSortedArr(vector<int> arr, int n) {
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int dupFindMinInRotatedSortedArr(vector<int> arr, int n){
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }

        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int minimumNum = FindMinInRotatedSortedArr(arr, n);
    cout << minimumNum;
    
    
    return 0;
}