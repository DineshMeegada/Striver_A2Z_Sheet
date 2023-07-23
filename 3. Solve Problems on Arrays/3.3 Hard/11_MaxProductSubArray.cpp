#include <bits/stdc++.h>
using namespace std;

// Striver's Approach
int maxProduct(vector<int> arr, int n){
    if (n==0) return -1;
    int res = INT_MIN, prefix = 1, suffix = 1;

    for (int i=0; i<n; i++){
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];

        res = max(res, max(prefix, suffix));
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int maxProd = maxProduct(arr, n);

    cout << maxProd ;
    
    return 0;
}