#include <bits/stdc++.h>
using namespace std;

bool isHeap(vector<int> arr, int n) {
    for (int i=0; i<n/2; i++) {
        int child1 = 2*i+1, child2 = 2*i+2;
        if (arr[child1]<arr[i] || arr[child2]<arr[i]) return false;
    }

    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << isHeap(arr, n);

    
    return 0;
}