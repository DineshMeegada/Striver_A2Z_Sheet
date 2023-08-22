#include <bits/stdc++.h>
using namespace std;

bool isPossible(char c, int i, int j, vector<vector<char>>& board){
    // row check
    for (int col=0; col<9; col++){
        if (board[i][col] == c) return false;
    }

    // col check
    for (int row=0; row<9; row++){
        if (board[row][j] == c) return false;
    }

    // box check
    int row1 = (i/3)*3, col1 = (j/3)*3;
    for (int row=row1; row<row1+3; row++){
        for (int col=col1; col<col1+3; col++){
            if(board[row][col] == c) return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>>& board){

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++) {
            if (board[i][j] == '.') {
                for (char c='1'; c<='9'; c++) {
                    if (isPossible(c, i, j, board)){
                        board[i][j] = c;
                        if (solve(board))  return true;
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    bool isSolve = solve(board);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    vector<vector<char>> board(9, vector<char>(9));

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++) cin >> board[i][j];
    }

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++) {
            cout << board[i][j] << ' ' ;
        }
        cout << endl;
    }

    solveSudoku(board);
    cout << endl << endl;

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++) cout << board[i][j] << ' ';
        cout << endl;
    }

    
    return 0;
}