#include <bits/stdc++.h>
using namespace std;


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m; 
    cin >> n >> m;

    // Using Adjacent Matrix 
    int adj1[n+1][n+1];

    for (int i=0; i<m; i++) {
        int u, v ;
        cin >> u >> v;

        adj1[u][v] = 1;

        // for Undirected Graph
        adj1[v][u] = 1;
    }

    // Using adjacency list
    vector<int> adj2[n+1];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adj2[u].push_back(v);

        // for undirected graph
        adj2[v].push_back(u);
    }

    // Using Adjacency Matrix with Weights
    int adj3[n+1][n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj3[u][v] = wt;

        // for undirected graph
        adj3[v][u] = wt;
    }

    // Using Adjacency List with Weights
    vector<pair<int, int>> adj4[n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj4[u].push_back({v, wt});

        // for undirected graph
        adj4[v].push_back({u, wt});
    }


    
    
    return 0;
}