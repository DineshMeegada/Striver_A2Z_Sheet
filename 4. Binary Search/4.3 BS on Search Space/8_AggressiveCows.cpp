#include <bits/stdc++.h>
using namespace std;

bool isFit (vector<int> stalls, int cows, int distance){
    int allot_cows = 1, prev = 0;
    for (int i=0; i<stalls.size(); i++){
        if(stalls[i] - stalls[prev] > distance) {
            allot_cows++;
            prev = i;
        }
    }
    
    return (allot_cows >= cows);
}

int solve(int n, int k, vector<int> &stalls) {

    // Write your code here
    sort(stalls.begin(), stalls.end());
    int low = 1, high = 1e9;
    
    while (low < high ) {
        int mid = low + (high - low) / 2;
        
        if (isFit(stalls, k, mid)) low = mid + 1;
        else high = mid;
    }
    
    return high;
    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    int maximized_min_distance = solve(n, k, arr);
    cout << maximized_min_distance; 
    
    
    return 0;
}