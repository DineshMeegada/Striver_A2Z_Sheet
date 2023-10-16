#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<int> adj[n];
    for (auto it: edges){
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distance(n, 1e9);

    queue<int> q;
    q.push(src);
    distance[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        int dist = distance[node];
        q.pop();
        

        for (auto it: adj[node]) {
            if (distance[it]>dist+1){
                q.push(it);
                distance[it] = dist+1;
            }
        }
    }

    for (int i=0; i<n; i++){
        if (distance[i]==1e9) distance[i] = -1;
    }

    return distance;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}