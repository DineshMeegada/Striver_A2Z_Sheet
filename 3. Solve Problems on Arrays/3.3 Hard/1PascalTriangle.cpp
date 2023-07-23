#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getTriangle(int n){
	vector<vector<int>> triArr(n);
	for(int i=0; i<n; i++){		
		triArr[i].resize(i+1);
		triArr[i][0] = triArr[i][i] = 1;
		
		for (int j=1; j<i; j++){
			triArr[i][j] = triArr[i-1][j-1] + triArr[i-1][j];
		}
	}
	
	return triArr;
}

vector<int> getRow(int n){
	vector<int> pascalRow(n+1);
	int ele = 1;
	for (int i=0; i<=n; i++){
		pascalRow[i] = ele;
		ele = ele * (n-i)/(i+1);
	}
	
	return pascalRow;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<vector<int>> triangle = getTriangle(n);
	
	for(int i=0; i<n; i++){
		for (int j = 0; j<=i; j++){
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	vector<int> pascalRow = getRow(n-1);
	for (int it: pascalRow) cout << it << " " ;

}


