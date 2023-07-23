#include <bits/stdc++.h>
using namespace std;

int bouqCount(vector<int> bloomDay, int mid, int k) {
    int n = bloomDay.size();
    int flow = 0, bouq = 0;
    for (int i=0; i<n; i++) {
        if (bloomDay[i] > mid) flow = 0;
        else flow++;

        if (flow >= k) {
            bouq++;
            flow = 0;
        }
    }
    return bouq;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if ((long long)m*k > n) return -1; 

    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        int bouq = bouqCount(bloomDay, mid, k);
        if (bouq >= m) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int days = minDays(arr, m, k);
    cout << days;
    
    return 0;
}