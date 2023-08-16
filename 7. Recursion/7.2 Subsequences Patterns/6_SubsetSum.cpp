#include <bits/stdc++.h>
using namespace std;

bool recurse(int ind, vector<int> arr, int k){
    if (k == 0) return true;
    if (ind < 0) return false;

    if (k-arr[ind]>=0 && recurse(ind-1, arr, k-arr[ind])) return true;
    if (recurse(ind-1, arr, k)) return true;


    return false; 
}

bool isSubsetPresent(int n, int k, vector<int> &arr)
{
    // Write your code here
    return recurse(n-1, arr, k);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;

    cout << isSubsetPresent(n, k, arr);
    
    return 0;
}