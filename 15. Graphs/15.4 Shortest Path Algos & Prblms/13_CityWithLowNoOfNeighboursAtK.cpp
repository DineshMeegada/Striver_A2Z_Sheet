#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int k) {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for (int i=0; i<n; i++) matrix[i][i] = 0;

    for (auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        matrix[u][v] = wt;
        matrix[v][u] = wt;
    }

    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (matrix[i][k]!=1e9 && matrix[k][i]!=1e9)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
            }
        }
    }

    int city = -1, neighbours = n;
    for (int i=0; i<n; i++){
        int cnt = 0;
        for (int j=0; j<n; j++){
            if (i!=j && matrix[i][j]<=k) cnt++;
        }

        if (cnt <= neighbours){
            neighbours = cnt;
            city = i;
        }
    } 

    return city;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, e, k;
    cin >> n >> e >> k;
    
    vector<vector<int>> edges;
    for (int i=0; i<e; i++){
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt});
    }

    int city = findTheCity(n, edges, k);
    cout << city;
    
    
    return 0;
}