#include <bits/stdc++.h>
using namespace std;


void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    
    int m = grid.size();
    int n = grid[0].size();
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                int nrow = r + i;
                int ncol = c + j;
                
                if (nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int cnt = 0;
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j]=='1' && !vis[i][j]){
                cnt++;
                bfs(i, j, vis, grid);
            }
        }
    }
    
    return cnt;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;

    vector<vector<char>> mat(m, vector<char>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
    
    int islands = numIslands(mat);
    cout << islands;
    
    
    return 0;
}