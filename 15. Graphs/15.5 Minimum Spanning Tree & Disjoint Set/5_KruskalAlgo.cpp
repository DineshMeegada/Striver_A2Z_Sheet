#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet (int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;

        int par = findUPar(parent[node]);
        parent[node] = par;
        return par;
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return ;

        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_v] > rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};

int spanningTree(int v, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int,int>>> edges;
    for (int i=0; i<v; i++) {
        for (auto it: adj[i]) {
            int v = it[0];
            int wt = it[1];
            
            edges.push_back({wt, {i,v}});
        }
    }
    
    sort(edges.begin(), edges.end());

    DisjointSet ds(v);
    int mstWt = 0;
    for (auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        int ulp_u = ds.findUPar(u);
        int ulp_v = ds.findUPar(v);

        if (ulp_u != ulp_v) mstWt += wt;
        ds.unionByRank(u, v);
    }

    return mstWt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;
    for (int i=0; i<e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }


    
    
    return 0;
}