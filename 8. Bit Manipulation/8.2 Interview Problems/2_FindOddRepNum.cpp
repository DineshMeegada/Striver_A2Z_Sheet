#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xor1 = 0;
    for (int it: nums) xor1 ^= it;
    return xor1;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    
    cout << singleNumber(arr);
    
    
    return 0;
}