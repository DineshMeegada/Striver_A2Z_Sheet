#include <bits/stdc++.h>
using namespace std;

void paths(int row, int col, string temp, vector<vector<int>> &m, int n, vector<string> &res) {
    if (row<0 || col<0 || row==n || col==n || m[row][col]==0) return;

    if (row==n-1 && col==n-1){
        res.push_back(temp);
        return;
    }

    int c = m[row][col];
    m[row][col] = 0;

    temp.push_back('D');
    paths(row+1, col, temp, m, n, res);
    temp.pop_back();

    temp.push_back('L');
    paths(row, col-1, temp, m, n, res);
    temp.pop_back();
    
    temp.push_back('R');
    paths(row, col+1, temp, m, n, res);
    temp.pop_back();
    
    temp.push_back('U');
    paths(row-1, col, temp, m, n, res);
    temp.pop_back();

    m[row][col] = c;
    
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> res;
    paths(0, 0, "", m, n, res);
    if (!res.size()) return {"-1"};
    return res;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) cin >> maze[i][j];
    }

    vector<string> paths = findPath(maze, n);
    for (auto it: paths) cout << it << endl;

    
    return 0;
}