#include <bits/stdc++.h>
using namespace std;


int mooreAlgo(int arr[], int n){
	int cnt = 0;
	int ele = arr[0];
	
	for (int i=0; i<n; i++) {
		if (cnt == 0) ele = arr[i];
		if (arr[i] == ele) cnt++;
		else cnt--;
	}
	
	int count = 0;
	for (int i=0; i<n; i++){
		if (arr[i] == ele) count++;
	}
	
	if (count > n/2) return ele;
	return -1;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	cout << mooreAlgo(arr, n);

}

