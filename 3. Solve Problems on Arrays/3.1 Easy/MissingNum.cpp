#include <bits/stdc++.h>
using namespace std;

int sumType(int arr[], int n){
	int sum = n*(n+1)/2;
	int s = 0;
	for(int i=0; i<n-1; i++) s += arr[i] ;
	
	return sum - s;
}

int xorType(int arr[], int n){
	int xor1 = 0;
	for (int i=1; i<=n; i++) xor1 = xor1^i ;
	
	int xor2 = 0;
	for (int i=0; i<n-1; i++) xor2 = xor2^arr[i];
	
	return xor1^xor2;
}

int optimized(int arr[], int n){
	int xor2 = n;
	for (int i=0; i<n-1; i++){
		xor2 = xor2^(arr[i])^(i+1);
	}
	
	return xor2;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n-1; i++) cin >> arr[i] ;
	
	cout << optimized(arr, n);

}


