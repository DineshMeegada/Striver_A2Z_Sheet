#include <bits/stdc++.h>
using namespace std;

bool checkSort(int arr[], int n){
	for (int i=1; i<n; i++){
		if (arr[i]<arr[i-1]) return false;
	}
	return true;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	cout << checkSort(arr, n);

}


