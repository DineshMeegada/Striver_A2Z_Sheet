#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int insertIndex = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    cout << insertIndex;
    
    return 0;
}