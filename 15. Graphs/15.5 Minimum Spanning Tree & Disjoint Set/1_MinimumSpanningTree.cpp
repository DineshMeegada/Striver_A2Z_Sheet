#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minSpanningTree(int v, vector<vector<int>> adj[]){
    // {edgeWt, {node, parent}}
    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    vector<int> vis(v, 0);

    pq.push({0,{0,-1}});
    vector<vector<int>> ans;
    int val = 0;

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        val += wt;
        if (parent != -1) ans.push_back({parent, node});

        for (auto it: adj[node]){
            int adjNode = it[0];
            int adjWt = it[1];

            if (!vis[adjNode]){
                pq.push({adjWt, {adjNode, node}});
            }
        }
    }

    cout << "MST value : " << val << endl;
    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<vector<int>> ans = minSpanningTree(v, adj);
    for (auto iter: ans){
        for (auto it: iter) cout << it << ' ';
        cout << endl;
    }
    
    
    return 0;
}