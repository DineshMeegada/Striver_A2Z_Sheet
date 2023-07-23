#include <bits/stdc++.h>
using namespace std;

void bruteforce(int arr[], int n){
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i=0; i<n; i++) {
		if (arr[i] == 1) cnt1++;
		else if (arr[i] == 2) cnt2++;
		else cnt0++;
	}
	
	for(int i=0; i<cnt0; i++) arr[i] = 0;
	for(int i=cnt0; i<cnt0+cnt1; i++) arr[i] = 1;
	for(int i=cnt0+cnt1; i<n; i++) arr[i] = 2;
	
}

void DutchAlgo(int arr[], int n){
	int low = 0;
	int mid = 0;
	int high = n-1;
	
	while (mid <= high){
		if (arr[mid] == 0) swap(arr[mid++], arr[low++]);
		else if (arr[mid] == 2) swap(arr[mid], arr[high--]);
		else mid++;
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	DutchAlgo(arr, n);
	
	for(auto it: arr) cout << it << " ";
	

}
