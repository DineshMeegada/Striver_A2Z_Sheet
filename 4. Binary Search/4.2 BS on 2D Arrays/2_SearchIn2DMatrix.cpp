#include <bits/stdc++.h>
using namespace std;

int rowIndex (vector<vector<int>> matrix, int target){
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m-1;
    // cout << low << " " << high << endl;
    while (low <= high){
        int mid = (low + high) / 2;

        if (matrix[mid][0]<=target && matrix[mid][n-1]>=target) return mid;
        if (matrix[mid][n-1] < target) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int rowInd = rowIndex(matrix, target);

    int low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;

        if (matrix[rowInd][mid] == target) return true;
        if (matrix[rowInd][mid] > target) high = mid - 1;
        else low = mid + 1;
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