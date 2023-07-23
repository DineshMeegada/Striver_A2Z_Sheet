#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n){
	sort(arr, arr+n);
	return (arr[n-2]);
}

int optimized(int arr[], int n){
	int largest = arr[0];
	int second_largest;
	
	for (int i=0; i<n; i++){
		if (arr[i]>largest){
			second_largest = largest;
			largest = arr[i];
		}
		else if (arr[i]<largest && arr[i]>second_largest){
			second_largest = arr[i];
		}
	}
	
	return second_largest;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	for(auto it: arr) cout << it << " ";
	
	
	
	cout << endl << optimized(arr, n);
	


}


