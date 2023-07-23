#include <bits/stdc++.h>
using namespace std;

int findKRotations(vector<int> arr, int n){
    int low = 0, high = n-1;
    int ind = 0;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high]) {
            if (arr[low] < arr[ind]) ind = low;
            break;
        }
        else if (arr[low] <= arr[mid] ) {
            if (arr[low] < arr[ind]) ind = low;
            low = mid + 1;
        }
        else {
            if (arr[mid] <= arr[ind]) ind = mid;
            high = mid - 1;
        }
    }

    return ind;
}

int dupFindKRotations(vector<int> arr, int n){
    int low = 0, high = n-1;
    int ind = 0;

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }

        if (arr[low] <= arr[high]) {
            if (arr[low] < arr[ind]) ind = low;
            break;
        }
        else if (arr[low] <= arr[mid] ) {
            if (arr[low] < arr[ind]) ind = low;
            low = mid + 1;
        }
        else {
            if (arr[mid] <= arr[ind]) ind = mid;
            high = mid - 1;
        }
    }

    return ind;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int K = findKRotations(arr, n);
    cout << K;
    
    
    return 0;
}