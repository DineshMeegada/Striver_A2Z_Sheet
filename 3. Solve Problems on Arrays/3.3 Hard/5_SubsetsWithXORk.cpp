#include <bits/stdc++.h>
using namespace std;

int countxors(vector<int> arr, int n, int k){
	int count = 0;
	for (int i=0; i<n; i++){
		int xor1 = 0;
		for (int j=i; j<n; j++){
			xor1 = xor1 ^ arr[j];
			if (xor1 == k) count++;
		}
	}
	
	return count;
}

int countXorOpt(vector<int> arr, int n, int k) {
	unordered_map<int, int> freq;
	int count = 0, xr = 0;
	
	for(int i=0; i<n; i++){
		xr ^= arr[i];
		if(xr == k) count++;
		count += freq[xr^k];
		freq[xr]++;
	}
	return count;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;

	cout << countxors(arr, n, k) << endl;
	
	cout << countXorOpt(arr, n, k) << endl ;
	

}


