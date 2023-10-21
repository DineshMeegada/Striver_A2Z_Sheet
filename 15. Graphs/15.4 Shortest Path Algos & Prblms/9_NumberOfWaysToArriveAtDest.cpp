#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    int mod = (int)(1e9+7);

    vector<pair<int,int>> adj[n];
    for (auto it: roads){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> ways(n, 0);
    ways[0] = 1;

    vector<int> dist(n, 1e18);
    dist[0] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>> > pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]) {
            int currNode = it.first;
            int currWt = it.second;

            if (dist[currNode] > dis+currWt){
                dist[currNode] = dis+currWt;
                pq.push({dis+currWt, currNode});
                ways[currNode] = ways[node]%mod;
            } else if (dist[currNode] == dis+currWt){
                ways[currNode] = (ways[currNode]+ways[node])%mod;
            } 
        }
    }

    return (ways[n-1])%mod;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, e;
    cin >> n >> e;

    vector<vector<int>> roads(e);
    for (int i=0; i<e; i++){
        int u, v, wt;
        cin >> u >> v >> wt;

        roads[i] = {u, v, wt};
    }

    int ways = countPaths(n, roads);
    cout << ways ;
    
    
    
    return 0;
}