#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0]==1) return -1;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    vis[0][0] = 1;

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<int> drow = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> dcol = {1, 0, -1, 1, -1, 1, 0, -1};
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int dis = vis[row][col];
        q.pop();

        for (int i=0; i<8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && grid[nrow][ncol]==0 && vis[nrow][ncol]>1+dis){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1 + dis;
            }
        }
    }

    return (vis[n-1][m-1]==1e9) ? -1 : vis[n-1][m-1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> grid[i][j];
    }

    int dist = shortestPathBinaryMatrix(grid);
    cout << dist;
    
    
    
    return 0;
}