#include <bits/stdc++.h>
using namespace std;

// Using Priority Queue
vector <int> dijkstraPQ(int v, vector<vector<int>> adj[], int src) {
    vector<int> dist(v, 1e9);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]) {
            int adjNode = it[0];
            int adjWt = it[1];

            if (dist[adjNode] > dis+adjWt) {
                dist[adjNode] = dis+adjWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e, src;
    cin >> v >> e >> src;

    vector<vector<int>> adj[v];
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist = dijkstraPQ(v, adj, src);
    for (auto it: dist) cout << it << ' ';
    
    
    return 0;
}