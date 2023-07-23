#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n){
	int maxi = INT_MIN;
	for (int i=0; i<n; i++){
		for (int j=i; j<=n; j++){
			int sum = 0;
			for (int k=i; k<=j; k++){
				sum += arr[k];
			}
			maxi = max(maxi, sum);
		}
	}
	return maxi;
}

int better(int arr[], int n){
	int maxi = INT_MIN;
	for (int i=0; i<n; i++){
		int sum = 0;
		for (int j=i; j<n; j++){
			sum += arr[j];
			maxi = max(sum, maxi);
		}
	}
	return maxi;
}

int KadaneAlgo(int arr[], int n){
	int maxi = 0;
	int sum = 0;
	for (int i=0; i<n; i++){
		sum += arr[i];
		maxi = max(maxi, sum);
		if (sum < 0) sum = 0;
	}
	return maxi;
}

vector<int> KadaneArr(int arr[], int n){
	vector<int> res, temp;
	int maxi = 0, sum = 0;
	for (int i=0; i<n; i++){
		sum += arr[i];
		temp.push_back(arr[i]);
		if (sum > maxi){
			maxi = sum;
			res = temp;
		}
		if (sum < 0){
			sum = 0;
			temp.clear();
		}
	}
	return res;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	cout << KadaneAlgo(arr, n) << endl;
	vector<int> subArr = KadaneArr(arr, n);
	
	for (auto it: subArr) cout << it << " ";



}

