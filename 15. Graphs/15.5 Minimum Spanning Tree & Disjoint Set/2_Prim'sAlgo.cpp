#include <bits/stdc++.h>
using namespace std;

int spanningTree(int v, vector<vector<int>> adj[]){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> vis(v, 0);

    pq.push({0,0});
    int ans = 0;
    while (!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        ans += wt;

        for (auto it: adj[node]){
            if (!vis[it[0]]){
                pq.push({it[1], it[0]});
            }
        }
    }

    return ans;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];
    for (int i=0; i<e; i++){
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int MSTVal = spanningTree(v, adj);
    cout << MSTVal;

    
    
    return 0;
}