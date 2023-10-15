#include <bits/stdc++.h>
using namespace std;


vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> inDegree(v, 0);
    for (int i=0; i<v; i++) {
        for (auto it: adj[i]) {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i=0; i<v; i++) {
        if (inDegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        topo.push_back(curr);

        for (auto it: adj[curr]){
            inDegree[it]--;
            if (inDegree[it]==0) q.push(it);
        }
    }

    return topo;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m ;
    cin >> n >> m ;

    vector<int> adj[n];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> topo = topoSort(n, adj);
    for (auto it: topo) cout << it << ' ';
    
    return 0;
}