#include <bits/stdc++.h>
using namespace std;

int count_days(vector<int> weights, int capacity) {

    int days_count = 1, curr_weight = 0;

    for (int i=0; i<weights.size(); i++) {
        if (curr_weight + weights[i] > capacity) {
            days_count++;
            curr_weight = 0;
        }
        curr_weight += weights[i];
    }

    return days_count;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = 0, high = 25*1e6;

    for (int w: weights) low = max(low, w);

    while (low < high) {
        int capacity = low + (high - low) / 2;

        int curr_days = count_days(weights, capacity);

        if (curr_days > days) low = capacity + 1;
        else high = capacity;            
    }
    return low ;
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, days;
    cin >> n >> days ;

    vector<int> weights;
    for (int i=0; i<n; i++) cin >> weights[i];

    int minCapacity = shipWithinDays(weights, days);
    cout << minCapacity;

    return 0;
}