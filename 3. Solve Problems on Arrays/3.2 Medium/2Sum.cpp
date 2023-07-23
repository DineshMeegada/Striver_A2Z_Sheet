#include <bits/stdc++.h>
using namespace std;

bool brute(vector<int> arr, int n, int k){
	for(int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++){
			if (arr[i]+arr[j] == k) return true;
		}
	}
	return false;
}

bool optimized(vector<int> arr, int n, int k){
	map<int, int> mpp;
	for (int i=0; i<n; i++){
		int rem = k-arr[i];
		if (mpp.find(rem) != mpp.end()){
			return true;
		}
		mpp[arr[i]] = i;
	}
	return false;
}

bool positivesBest(vector<int> arr, int n, int k){
	int left = 0, right = n-1;
	while (left<right){
		int sum = arr[left] + arr[right] ;
		if (sum == k) return true;
		else if (sum < k) left++;
		else right++;
	}
	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, target;
	cin >> n >> target;
	
	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i];
	
	cout << optimized(arr, n, target) ;

}


