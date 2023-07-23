#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    int low = 0, high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;

        int rowMax = 0;
        for (int i=0; i<m; i++) {
            if (mat[i][mid] >= mat[rowMax][mid]) rowMax = i;
        }

        bool isLeftBig = (mid>0 && mat[rowMax][mid-1]>mat[rowMax][mid]);
        bool isRightBig = (mid<n-1 && mat[rowMax][mid+1]>mat[rowMax][mid]);

        if (!isLeftBig && !isRightBig) return {rowMax, mid};
        if (isLeftBig) high = mid - 1;
        else low = mid + 1;
    }

    return {-1, -1};

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

    vector<int> peakEle = findPeakGrid(matrix);
    cout << peakEle[0] << " " << peakEle[1];
    
    
    
    return 0;
}