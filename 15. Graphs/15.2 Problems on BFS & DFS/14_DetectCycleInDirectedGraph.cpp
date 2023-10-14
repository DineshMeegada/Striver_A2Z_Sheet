#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path) {
    vis[node] = 1;
    path[node] = 1;

    for (auto it: adj[node]) {
        if (!vis[it] && dfs(it, adj, vis, path)) return true;
        else if (path[it]) return true;
    }

    path[node] = 0;
    return false;
}

bool isCyclic(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    vector<int> path(v, 0);

    for (int i=0; i<v; i++) {
        if (!vis[i] && dfs(i, adj, vis, path)) return true; 
    }

    return false;
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(n, adj);
    

    
    return 0;
}