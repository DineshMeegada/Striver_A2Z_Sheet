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

void row_change(vector<vector<int>>& arr, int a, int n){
	for (int i=0; i<n; i++){
		if (arr[a][i] != 0) arr[a][i] = -1;
	}
}

void col_change(vector<vector<int>>& arr, int a, int n){
	for (int i=0; i<n; i++){
		if (arr[i][a] != 0) arr[i][a] = -1;
	}
}

void brute_change(vector<vector<int>>& arr, int m, int n){
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (arr[i][j] == 0){
				row_change(arr, i, n);
				col_change(arr, j, m);
			}
		}
	}
	
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (arr[i][j] == -1) arr[i][j] = 0;
		}
	}
}

void better_change(vector<vector<int>>& arr, int m, int n){
	vector<int> row(m, 1), col(n, 1);
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (arr[i][j] == 0){
				row[i] = 0;
				col[j] = 0;
			}
		}
	}
	
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (row[i] == 0 || col[j] == 0) arr[i][j] = 0;
		}
	}
}

void opt_change(vector<vector<int>>& arr, int m, int n){
	int col0 = 1;
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (arr[i][j] == 0){
				arr[i][0] = 0;
				if (j != 0) arr[0][j] = 0;
				else col0 = 0;
			}
		}
	}	
	
//	for (int i=1; i<m; i++){
//		for (int j=1; j<n; j++){
//			if (arr[0][j]==0 || arr[i][0]==0) arr[i][j] = 0;
//		}
//	}
//	if(arr[0][0] == 0){
//		for (int b=0; b<n; b++) arr[0][b] = 0; 
//	}
//	if (col0 == 0){
//		for (int a=0; a<m; a++) arr[a][0] = 0;
//	}


	for (int i=m-1; i>=0; i--){
		for (int j=n-1; j>0; j--){
			if (arr[0][j]==0 || arr[i][0]==0) arr[i][j] = 0;
		}
		if (col0 == 0) arr[i][0] = 0;
	}

}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> arr(m, vector<int>(n));
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cin >> arr[i][j] ;
		}
	}
	
	print_matrix(arr, m, n);
	
	opt_change(arr, m, n);

	cout << endl << endl;
	print_matrix(arr, m, n);


}


