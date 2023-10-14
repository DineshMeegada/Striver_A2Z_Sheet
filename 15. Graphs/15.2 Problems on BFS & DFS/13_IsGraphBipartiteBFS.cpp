#include <bits/stdc++.h>
using namespace std;


bool bfs(int node, vector<int>adj[],  vector<int> &colors){
    queue<int> q;
    q.push(node);

    colors[node] = 0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (auto it: adj[curr]){
            if (colors[it]==-1) {
                q.push(it);
                colors[it] = !colors[curr];
            }else if (colors[it]==colors[curr]) return false;
        }
    }

    return true;
}

bool isBipartite(int v, vector<int>adj[]){
    vector<int> colors(v, -1);

    for (int i=0; i<v; i++) {
        if (colors[i]==-1 && !bfs(i, adj, colors)) return false;
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