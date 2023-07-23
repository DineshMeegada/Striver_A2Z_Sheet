#include <bits/stdc++.h>
using namespace std;

vector<int> spiral_matrix(vector<vector<int>> matrix, int m, int n){
	int top = 0, left = 0;
	int bottom = m-1, right = n-1;
	vector<int> resArr;
	
	while (top<=bottom && left<=right){
		for (int i=left; i<=right; i++){
			resArr.push_back(matrix[top][i]);
		}
		top++;
		
		for(int i=top; i<=bottom; i++){
			resArr.push_back(matrix[i][right]);
		}
		right--;
		
		if (top<=bottom){
			for(int i=right; i>=left; i--){
				resArr.push_back(matrix[bottom][i]);
			}
			bottom--;
		}
		
		if (left<=right){
			for(int i=bottom; i>=top; i--){
				resArr.push_back(matrix[i][left]);
			}
			left++;
		}
	}
	
	return resArr;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> arr(m, vector<int>(n));
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++) cin >> arr[i][j] ;
	}
	
	vector<int> resArr = spiral_matrix(arr, m, n);
	
	for (auto it: resArr) cout << it << " ";



}


