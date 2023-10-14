#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &temp) {
    int n = grid.size(), m = grid[0].size();
    if (row<0 || row>=n || col<0 || col>=m || vis[row][col]==1 || grid[row][col]==0) return;

    vis[row][col] = 1;
    temp.push_back({row-sr, col-sc});

    vector<int> rowNums = {-1, 0, 1, 0};
    vector<int> colNums = {0, -1, 0, 1};

    for (int i=0; i<4; i++) {
        int nrow = row + rowNums[i];
        int ncol = col + colNums[i];

        dfs(nrow, ncol, sr, sc, grid, vis, temp);
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    set<vector<pair<int, int>>> inds;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j] && grid[i][j]==1) {
                vector<pair<int, int>> temp;
                dfs(i, j, i, j, grid, vis, temp);
                inds.insert(temp);
            }
        }
    }
    
    return inds.size();
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int> (m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j] ;
        }
    }

    int islands = countDistinctIslands(grid);
    cout << islands;
    
    
    return 0;
}