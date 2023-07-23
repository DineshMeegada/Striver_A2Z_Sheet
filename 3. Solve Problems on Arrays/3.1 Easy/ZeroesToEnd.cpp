#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr, int n){
	int j = -1;
	for (j=0; j<n; j++){
		if (arr[j] == 0) break;
	}
	
	for (int i=j+1; i<n; i++){
		if (arr[i] != 0) {
			swap(arr[j], arr[i]);
			j++;
		}
	}
	
	return arr;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; 
	cin >> n;
	
	vector<int> arr(n) ;
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	vector<int> res = optimal(arr, n);
	
	for(auto it: res) cout << it << " " ;
	
}


