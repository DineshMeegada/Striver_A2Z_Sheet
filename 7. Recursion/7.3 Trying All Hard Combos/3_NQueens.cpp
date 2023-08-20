#include <bits/stdc++.h>
using namespace std;

void mark(int row, int col, vector<string> &mat, int n){

    // Marking row
    for (int i=0; i<n; i++){
        mat[row][i] = '.';
    }

    // Marking col
    for (int i=row; i<n; i++){
        mat[i][col] = '.';
    }

    // Marking left diagnol
    int i=row, j=col;
    while (i<n && j>=0){
        mat[i++][j--] = '.';
    }

    // Marking right diagnol
    int i1=row, j1=col;
    while (i1<n && j1<n){
        mat[i1++][j1++] = '.';
    }

    mat[row][col] = 'Q';

}

void solve(int row, int col, vector<string> curr, vector<vector<string>> &res, int n){
    mark(row, col, curr, n);

    if (row==n-1){
        res.push_back(curr);
        return;
    }

    for (int i=0; i<n; i++){
        if (curr[row+1][i] == '0'){
            solve(row+1, i, curr, res, n);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> mat;
    string zeroes(n, '0');
    for (int a=0; a<n; a++){
        mat.push_back(zeroes);
    }

    vector<vector<string>> res;
    for (int i=0; i<n; i++) {
        solve(0, i, mat, res, n);
    }

    return res;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);
    for (auto sols: solutions){
        for (auto it: sols) cout << it << endl;
        cout << endl;
    }


    
    return 0;
}