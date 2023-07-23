#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n-1;
    while (row<m && col>=0) {
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target) col--;
        else row++;
    }

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
	cin >> m >> n;

	vector<vector<int>> matrix(m, vector<int>(n));
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++) cin >> matrix[i][j];
	}

    int target;
    cin >> target;

    bool isTargetInMat = searchMatrix(matrix, target);
    cout << isTargetInMat;
    
    
    
    return 0;
}