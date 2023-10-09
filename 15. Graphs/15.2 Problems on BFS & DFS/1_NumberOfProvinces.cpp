#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    
    for (auto it: adj[node]) {
        if (!vis[it]) dfs(it, vis, adj);
    }
}

int findNumOfProvinces(vector<vector<int>> &mat, int v) {
    vector<int> adj[v+1];
    for (int i=1; i<=v; i++) {
        for (int j=1; j<=v; j++) {
            if (i!=j && mat[i-1][j-1]==1) {
                adj[i].push_back(j);
            }
        }
    }
    
    vector<int> vis(v+1);
    int cnt = 0;
    for (int i=1; i<=v; i++) {
        if (vis[i] == 0) {
            cnt++;
            dfs(i, vis, adj);
        }
    }
    
    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v;
    cin >> v;
    
    vector<vector<int>> mat(v, vector<int>(v));
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            cin >> mat[i][j] ;
        }
    }

    int provinces = findNumOfProvinces(mat, v);
    cout << provinces ;
    
    return 0;
}