#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, 
vector<int> &check) {
    vis[node] = 1;
    path[node] = 1;
    check[node] = 0;

    for (auto it: adj[node]) {
        if (!vis[it] && dfs(it, adj, vis, path, check)) return true;
        else if (path[it]) return true;
    }
    
    check[node] = 1;
    path[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
    vector<int> vis(v, 0), path(v, 0), check(v, 0);
    vector<int> safeNodes;

    for (int i=0; i<v; i++) {
        if (!vis[i]) dfs(i, adj, vis, path, check);
    }
    
    for (int i=0; i<v; i++) {
        if (check[i]) safeNodes.push_back(i); 
    }

    return safeNodes;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}