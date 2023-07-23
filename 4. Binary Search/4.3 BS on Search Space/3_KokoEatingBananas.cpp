#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int low = 1, high = 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;

        long long int total = 0;
        for (int i=0; i<n; i++){
            total += 1 + (piles[i] - 1) / mid;
        }

        if(total > h) low = mid+1 ;
        else high = mid-1;
    }

    return low;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, h;
    cin >> n >> h;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int speed = minEatingSpeed(arr, h);
    cout << speed;


    return 0;
}