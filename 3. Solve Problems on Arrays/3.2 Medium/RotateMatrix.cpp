#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> arr, int m, int n){
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cout << arr[i][j] << " " ;
		}
		cout << endl;
	}
}

vector<vector<int>> brute_force(vector<vector<int>> matrix, int m, int n){
	vector<vector<int>> resArr(m, vector<int>(n));
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			resArr[j][n-i-1] = matrix[i][j];
		}
	}
	
	return resArr;
}

void rotateMatrix(vector<vector<int>>& matrix, int m, int n){
	for (int i=0; i<m-1; i++){
		for (int j=i+1; j<n; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	
	for (int i=0; i<m; i++){
		reverse(matrix[i].begin(), matrix[i].end());
	}

}

void rotateAnti(vector<vector<int>>& matrix, int m, int n){
	for (int i=0; i<m-1; i++){
		for (int j=0; j<n-i-1; j++){
			swap(matrix[i][j], matrix[n-j-1][n-i-1]);
		}
	}
	
	for (int i=0; i<m; i++){
		reverse(matrix[i].begin(), matrix[i].end());
	}
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
	
	print_matrix(matrix, m, n);
	
	vector<vector<int>> resMatrix = brute_force(matrix, m, n);
	
	cout << endl << endl ;
	print_matrix(resMatrix, m, n);
	
	rotateAnti(matrix, m, n);
	
	cout << endl << endl ;
	print_matrix(matrix, m, n);




}


