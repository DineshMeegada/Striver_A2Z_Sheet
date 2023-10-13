#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &board, vector<vector<char>> &res){
    int n = board.size(), m = board[0].size();
    if (row<0 || row>=n || col<0 || col>=m || board[row][col]!='O' || res[row][col]=='O') return;

    res[row][col] = 'O';

    vector<int> rowNums = {-1, 0, 1, 0};
    vector<int> colNums = {0, -1, 0, 1};

    for (int i=0; i<4; i++) {
        int nrow = row + rowNums[i];
        int ncol = col + colNums[i];

        dfs(nrow, ncol, board, res);
    }
    
}

vector<vector<char>> fill(vector<vector<char>> board) {
    int n = board.size(), m = board[0].size();
    vector<vector<char>> res(n, vector<char>(m, 'X'));

    for (int i=0; i<n; i++) {
        if (board[i][0]=='O' && res[i][0]=='X') dfs(i, 0, board, res);
        if (board[i][m-1]=='O' && res[i][m-1]=='X') dfs(i, m-1, board, res);
    }

    for (int i=0; i<m; i++) {
        if (board[0][i]=='O' && res[0][i]=='X') dfs(0, i, board, res);
        if (board[n-1][i]=='O' && res[n-1][i]=='X') dfs(n-1, i, board, res);
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char> (m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> board[i][j];
    }

    vector<vector<char>> res = fill(board);
    for (auto row: res) {
        for (auto it: row) cout << it << ' ';
        cout << endl;
    }


    
    
    
    return 0;
}