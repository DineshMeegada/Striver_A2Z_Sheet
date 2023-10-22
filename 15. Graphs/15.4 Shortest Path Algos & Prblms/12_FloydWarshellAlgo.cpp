#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j]==-1) matrix[i][j] = 1e9;
            if (i==j) matrix[i][j] = 0;
        }
    }

    for (int a=0; a<n; a++) {
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int dist = matrix[i][a]+matrix[a][j];
                matrix[i][j] = min(dist, matrix[i][j]);
            }
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j]==1e9) matrix[i][j] = -1;
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) cin >> matrix[i][j];
    }

    shortest_distance(matrix);
    for (auto iter: matrix){
        for (auto it: iter) cout << it << ' ';
        cout << endl;
    }
    
    
    
    return 0;
}