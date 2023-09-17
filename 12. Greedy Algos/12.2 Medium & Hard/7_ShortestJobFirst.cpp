#include <bits/stdc++.h>
using namespace std;

bool compare (pair<int, int> a, pair<int, int> b){
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    if (a.second < b.second) return true;
    return false;
}

float sjf(int n, vector<int> &arrival, vector<int> &burst) {
    vector<pair<int, int>> intervals;
    for (int i=0; i<n; i++) {
        intervals.push_back({arrival[i], burst[i]});
    }
    sort(intervals.begin(), intervals.end(), compare);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({intervals[0].second, intervals[0].first});

    int curr_time = intervals[0].first, wait_time = 0, i = 1;
    while(!pq.empty()){
        int burst_time = pq.top().first;
        int arr_time = pq.top().second;
        pq.pop();

        wait_time += curr_time - arr_time;
        curr_time += burst_time;

        while (i<n && intervals[i].first <= curr_time) {
            pq.push({intervals[i].second, intervals[i].first});
            i++;
        }
    }

    return (float)wait_time/(float)n;
    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arrival(n), burst(n);
    for (int i=0; i<n; i++){
        cin >> arrival[i] >> burst[i];
    }

    float avg_wait = sjf(n, arrival, burst);
    cout << avg_wait ;
    
    
    return 0;
}