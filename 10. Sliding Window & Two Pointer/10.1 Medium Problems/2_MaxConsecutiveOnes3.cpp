#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &arr, int k) {
    int left = 0, n = arr.size();
    int len = 0;

    for (int i=0; i<n; i++) {
        if (arr[i] == 0) k--;
        while (k<0) if (arr[left++]==0) k++;
        len = max(len, i-left+1);
    }

    return len;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int count = longestOnes(arr, k);
    cout << count;
    
    return 0;
}