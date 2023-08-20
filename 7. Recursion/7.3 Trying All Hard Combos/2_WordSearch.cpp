#include <bits/stdc++.h>
using namespace std;


bool search(int ind, string &word, int i, int j, vector<vector<char>> &board){
    if (ind==word.size()) return true;

    if (i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[ind] || board[i][j]=='!'){
        return false;
    }

    char c = board[i][j];
    board[i][j] = '!';
    
    bool check1 = search(ind+1, word, i-1, j, board);
    bool check2 = search(ind+1, word, i, j+1, board);
    bool check3 = search(ind+1, word, i+1, j, board);
    bool check4 = search(ind+1, word, i, j-1, board);

    board[i][j] = c;

    return (check1 || check2|| check3|| check4);

}

bool exist(vector<vector<char>>& board, string word) {

    for (int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if (board[i][j] == word[0]){
                if (search(0, word, i, j, board)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) cin >> board[i][j];
    }

    string word;
    cin >> word;

    // for (int i=0; i<m; i++){
    //     for (int j=0; j<n; j++) cout << board[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << word;

    cout << exist(board, word);

    
    return 0;
}