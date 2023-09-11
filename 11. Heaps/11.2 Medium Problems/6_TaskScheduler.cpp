#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int k) {
    unordered_map<char, int> mp;
    for (auto it: tasks) mp[it]++;

    priority_queue<int> pq;
    for (auto it: mp) pq.push(it.second);

    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;

        for (int i=0; i<=k; i++) {
            if (!pq.empty()){
                temp.push_back(pq.top());
                pq.pop();
            }
        }

        for (int i=0; i<temp.size(); i++) {
            if (--temp[i]>0) pq.push(temp[i]);
        }

        time += !pq.empty() ? k+1 : temp.size();
    }

    return time;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<char> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int time = leastInterval(arr, k);
    cout << time ;

    
    return 0;
}