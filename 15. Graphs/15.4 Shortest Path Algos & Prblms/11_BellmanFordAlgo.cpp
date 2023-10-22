#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
    vector<int> dist(v, 1e8);
    dist[src] = 0;

    for (int i=0; i<v-1; i++){
        for (auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }

    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e8 && dist[u]+wt < dist[v]) return {-1};
    }

    cout << "Returning " << endl;

    return dist;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e, src;
    cin >> v >> e;

    vector<vector<int>> edges(e);
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges[i] = {u, v, wt};
    }

    cin >> src;


    vector<int> dist = bellman_ford(v, edges, src);
    for (auto it: dist) {
        cout << it << ' ' ;
    }
    cout << endl;
    
    
    
    return 0;
}