#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    
    for (auto it: adj[node]){
        int v = it.first;
        if (!vis[v]) dfs(v, adj, vis, st);
    }
    
    st.push(node);
}

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
    vector<pair<int,int>> adj[n];
    for (int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        adj[u].push_back({v, wt});
    }
    
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i=0; i<n; i++) {
        if (!vis[i]) dfs(i, adj, vis, st);
    }
    
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        int d = dist[curr];
        
        for (auto it: adj[curr]){
            dist[it.first] = min(dist[it.first], d+it.second);
        }
    }
    
    for (int i=0; i<n; i++) {
        if (dist[i]==1e9) dist[i] = -1;
    }
    
    return dist;
    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}