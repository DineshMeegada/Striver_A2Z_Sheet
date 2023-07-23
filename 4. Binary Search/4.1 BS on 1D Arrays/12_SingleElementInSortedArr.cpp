#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int> arr, int n){
    if (n==1) return arr[0];

    int low = 1, high = n-2;
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];

    while (low <= high){
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) return arr[mid];
        if ((mid%2==1 && arr[mid]!=arr[mid-1]) || (mid%2==1 && arr[mid]!=arr[mid+1])) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int singleNum = findSingleElement(arr, n);
    cout << singleNum;
    
    
    return 0;
}