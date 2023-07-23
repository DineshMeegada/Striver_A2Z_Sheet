#include <bits/stdc++.h>
using namespace std;

int brute_force(int arr[], int n){
	sort(arr, arr + n);	
	return arr[n-1] ;
}

int optimized(int arr[], int n){
	int largest = arr[0];
	for (int i=0; i<n; i++){
		if (arr[i]>largest){
			largest = arr[i] ;
		}
	}
	
	return largest;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr[n] ;
	for (int i=0; i<n; i++) cin >> arr[i];
	
	for(auto it: arr) cout << it << " ";
	cout << endl;
	
//	cout << brute_force(arr, n);
	
	cout << optimized(arr, n) ;
}


