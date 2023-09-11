#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int k) {
    int n = hand.size();
    if (n%k != 0) return false;

    unordered_map<int, int> mp;
    for (int it: hand) mp[it]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it: mp) pq.push(it);

    while (!pq.empty()) {
        vector<pair<int, int>> temp;
        
        for (int i=0; i<k; i++) {
            if (!temp.empty() && pq.top().first != temp.back().first+1) return false; 
            temp.push_back(pq.top());
            pq.pop();
        }

        for (int i=0; i<k; i++) {
            if(--temp[i].second > 0) pq.push(temp[i]);
        }
    }

    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << isNStraightHand(arr, k);
    
    
    return 0;
}