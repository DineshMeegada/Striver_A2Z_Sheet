#include <bits/stdc++.h>
using namespace std;


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k; 
	cin >> n >> k;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	for(int it: arr) cout << it << " ";
	cout << endl << endl;
	
	reverse(arr, arr+k);
	for(int it: arr) cout << it << " ";
	cout << endl << endl;
	
	reverse(arr+k, arr+n);
	for(int it: arr) cout << it << " ";
	cout << endl << endl;
	
	reverse(arr, arr+n);
	for(int it: arr) cout << it << " ";

}


