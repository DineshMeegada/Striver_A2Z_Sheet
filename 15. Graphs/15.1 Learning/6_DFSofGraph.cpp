#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path) {
    if (vis[node] == 1) return ;
    vis[node] = 1;
    path.push_back(node);

    for (auto it: adj[node]){
        dfs(it, adj, vis, path);
    }
}

vector<vector<int>> depthFirstSearch(int n, int e, vector<vector<int>> &edges){
    vector<int> adj[n];
    for (int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> comps;
    vector<int> visited(n);

    for (int i=0; i<n; i++) {
        if (visited[i] == 0) {
            vector<int> path;
            dfs(i, adj, visited, path);
            comps.push_back(path);
        }
    }

    return comps;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;
    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> ans = depthFirstSearch(v, e, edges);
    for (auto comp: ans) {
        for (auto it: comp) cout << it << ' ';
        cout << endl; 
    }
    
    
    
    return 0;
}