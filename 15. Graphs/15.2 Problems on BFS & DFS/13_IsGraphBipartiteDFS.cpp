#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, int paint, vector<int>adj[],  vector<int> &colors){
    colors[node] = paint;

    for (auto it: adj[node]) {
        if (colors[it]==-1 && !dfs(it, !paint, adj, colors)) return false;
        if (colors[it]==paint) return false;
    }

    return true;
}

bool isBipartite(int v, vector<int>adj[]){
    vector<int> colors(v, -1);

    for (int i=0; i<v; i++) {
        if (colors[i]==-1 && !dfs(i, 0, adj, colors)) return false;
    }

    return true;
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

    cout << isBipartite(n, adj);

    
    
    
    return 0;
}