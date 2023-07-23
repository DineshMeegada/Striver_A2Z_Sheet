#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n){
	int profit = INT_MIN;
	int minPrice = arr[0];
	for (int i=0; i<n; i++){
		minPrice = min(minPrice, arr[i]);
		profit = max(profit, arr[i]-minPrice);
	}
	return profit;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	cout << maxProfit(arr, n);

}

