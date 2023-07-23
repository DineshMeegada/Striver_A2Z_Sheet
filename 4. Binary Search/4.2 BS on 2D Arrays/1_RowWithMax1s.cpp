#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int index = -1, count = 0;
    for (int i=0; i<n; i++){
        int curr_count = m - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
        // cout << curr_count << " " << count << endl;
        if (curr_count > count) {
            count = curr_count;
            index = i;
        }
    }
    
    return index;
}


void print_matrix(vector<vector<int>> arr, int m, int n){
	for(int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cout << arr[i][j] << " " ;
		}
		cout << endl;
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
    
    int max1sRow = rowWithMax1s(matrix, m, n);
    cout << max1sRow;
    
    
    return 0;
}