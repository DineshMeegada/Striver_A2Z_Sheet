#include <bits/stdc++.h>
using namespace std;

int Iterative_BS(vector<int> arr, int n, int k){
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) return mid;
        else if (arr[mid] > k) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int Recursive_BS (vector<int> arr, int low, int high, int k) {
    if (low > high) return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == k) return mid;
    else if (arr[mid] > k) return (Recursive_BS(arr, low, mid-1, k));
    else return (Recursive_BS(arr, mid+1, high, k));
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int index = Recursive_BS(arr, 0, n-1, k);

    cout << index ;
    
    
    return 0;
}