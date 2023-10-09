#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &vis, int color, int curr) {
    if (row<0 || row>=image.size() || col<0 || col>=image[0].size()
    || vis[row][col]==1 || image[row][col]!=curr) return;

    vis[row][col] = 1;
    image[row][col] = color;

    dfs(row-1, col, image, vis, color, curr);
    dfs(row+1, col, image, vis, color, curr);
    dfs(row, col-1, image, vis, color, curr);
    dfs(row, col+1, image, vis, color, curr);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int n, int m, int sr, int sc, int color) {
    int curr = image[sr][sc];
    vector<vector<int>> vis(n, vector<int>(m));
    dfs(sr, sc, image, vis, color, curr);
    return image;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;

    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> image(m, vector<int>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> image[i][j];
        }
    }
    
    vector<vector<int>> floodImage = floodFill(image, m, n, sr, sc, color);
    for (auto row: floodImage){
        for (auto it: row) cout << it << ' ';
        cout << endl;
    }
    
    
    return 0;
}