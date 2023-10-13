#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>> mat, vector<vector<int>> &vis) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 0) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } 
        }
    }

    vector<int> rowNums = {-1, 0, 1, 0};
    vector<int> colNums = {0, 1, 0, -1};
    while (!q.empty()) {
        auto curr = q.front();
        int r = curr.first.first;
        int c = curr.first.second;
        int dist = curr.second;
        q.pop();

        res[r][c] = dist;

        for (int i=0; i<4; i++) {
            int newRow = r + rowNums[i];
            int newCol = c + colNums[i];

            if (newRow>=0 && newRow<n && newCol>=0 && newCol<m 
            && vis[newRow][newCol]==0){
                q.push({{newRow, newCol}, dist+1});
                vis[newRow][newCol] = 1;
            }
        }
    }

    return res;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    vector<vector<int>> res = solve(mat, vis);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> resMatrix = updateMatrix(mat);
    for (auto row: resMatrix) {
        for (auto it: row) cout << it << ' ';
        cout << endl;
    }
    
    
    
    return 0;
}