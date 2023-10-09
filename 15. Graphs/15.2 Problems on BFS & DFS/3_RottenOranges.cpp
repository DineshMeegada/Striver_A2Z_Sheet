#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } 
        }
    }

    int count = 0;
    vector<int> dmrow = {-1, 0, 1, 0};
    vector<int> dmcol = {0, -1, 0, 1};
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int cnt = q.front().second;
        count = max(cnt, count);
        q.pop();

        for (int i=0; i<4; i++) {
            int nrow = row + dmrow[i];
            int ncol = col + dmcol[i];

            if (nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({{nrow, ncol}, cnt+1});
                vis[nrow][ncol] = 1;
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (vis[i][j]!=1 && grid[i][j]==1) return -1;
        }
    }

    return count;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    int time = orangesRotting(grid);
    cout << time;
    
    
    
    return 0;
}