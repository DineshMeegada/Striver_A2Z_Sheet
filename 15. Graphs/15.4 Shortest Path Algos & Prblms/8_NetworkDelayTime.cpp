#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int src) {
    vector<pair<int, int>> adj[n+1];
    for (auto it: times){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
    }

    vector<int> timeArr(n+1, 1e9);
    timeArr[src] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int t = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]) {
            int currNode = it.first;
            int currT = it.second;

            if (timeArr[currNode] > t+currT){
                timeArr[currNode] = t+currT;
                pq.push({t+currT, currNode});
            }
        }
    }

    int maxTime = 0;
    for (int i=1; i<=n; i++){
        if (timeArr[i]==1e9) return -1;
        maxTime = max(maxTime, timeArr[i]);
    }

    return maxTime;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, e;
    cin >> n >> e;

    vector<vector<int>> times(e);
    for (int i=0; i<e; i++){
        int u, v, wt;
        cin >> u >> v >> wt;

        times[i] = {u, v, wt};
    }

    int src ;
    cin >> src;

    int time = networkDelayTime(times, n, src);
    cout << time;
    
    
    
    return 0;
}