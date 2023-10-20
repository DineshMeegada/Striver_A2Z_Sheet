#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algo to find the path
vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[v+1];
    for (auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(v+1, 1e9);
    dist[1] = 0;

    vector<int> parent(v+1);
    for (int i=1; i<=v; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it: adj[node]){
            int adjNode = it.first;
            int adjWt = it.second;

            if (dis+adjWt < dist[adjNode]){
                dist[adjNode] = dis+adjWt;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    if (dist[v] == 1e9) return {-1};

    vector<int> ans;
    int i = v;
    while (i != 1){
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e ;

    vector<vector<int>> edges;
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    vector<int> dist = shortestPath(v, e, edges);
    for (auto it: dist) cout << it << ' ';
    
    
    return 0;
}