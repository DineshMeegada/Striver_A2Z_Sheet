#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> adj[n];
    for (auto it: flights){
        int from = it[0];
        int to = it[1];
        int wt = it[2];

        adj[from].push_back({to, wt});
    }

    vector<int> vis(n, 1e9);
    vis[src] = 0;

    // q {{steps, cost}, node}
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0}, src});

    while (!q.empty()) {
        auto iter = q.front();
        int steps = iter.first.first;
        int cost = iter.first.second;
        int node = iter.second;
        q.pop();

        for (auto it: adj[node]){
            int nNode = it.first;
            int wt = it.second;

            if (steps<=k && cost+wt<vis[nNode]){
                vis[nNode] = cost+wt;
                q.push({{steps+1, cost+wt}, nNode});
            }
        }
    }

    return (vis[dst]==1e9) ? -1 : vis[dst];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, e;
    cin >> n >> e;

    vector<vector<int>> flights;
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        flights.push_back({u, v, wt});
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    int price = findCheapestPrice(n, flights, src, dst, k);
    cout << price;
    
    
    
    return 0;
}