#include <bits/stdc++.h>
using namespace std;


void dfs(int row, int col, vector<vector<int>> &board, vector<vector<int>> &res){
    int n = board.size(), m = board[0].size();
    if (row<0 || row>=n || col<0 || col>=m || board[row][col]!=0 || res[row][col]==1) return;

    res[row][col] = 1;

    vector<int> rowNums = {-1, 0, 1, 0};
    vector<int> colNums = {0, -1, 0, 1};

    for (int i=0; i<4; i++) {
        int nrow = row + rowNums[i];
        int ncol = col + colNums[i];

        dfs(nrow, ncol, board, res);
    }
    
}

int matrixTraps(vector<vector<int>> &board) {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        if (board[i][0]==0 && res[i][0]==0) dfs(i, 0, board, res);
        if (board[i][m-1]==0 && res[i][m-1]==0) dfs(i, m-1, board, res);
    }

    for (int i=0; i<m; i++) {
        if (board[0][i]==0 && res[0][i]==0) dfs(0, i, board, res);
        if (board[n-1][i]==0 && res[n-1][i]==0) dfs(n-1, i, board, res);
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==0 && res[i][j]==0) cnt++;
        }
    }

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int> (m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> board[i][j];
    }

    int res = matrixTraps(board);
    cout << res;


    
    
    
    return 0;
}