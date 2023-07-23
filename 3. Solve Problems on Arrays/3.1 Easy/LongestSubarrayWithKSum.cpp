#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N^3)
int bruteON3(vector<int> arr, int n, int k){
	int maxlen = 0;
	for(int i=0; i<n; i++) {
		for (int j=i; j<n; j++){
			int sum = 0;
			for (int k=i; k<=j; k++){
				sum += arr[k];
			}
			if (sum == k){
				maxlen = max(maxlen, j-i+1);
			}
		}
	}
	return maxlen;
}

// Time Complexity - O(N^2)
int bruteON2(vector<int> arr, int n, int k){
	int maxlen = 0;
	for (int i=0; i<n; i++){
		int sum = 0;
		for (int j=i; j<=n; j++){
			sum += arr[j];
			if (sum == k) {
				maxlen = max(maxlen, j-i+1);
				cout << sum << " " << i << " " << j << " " << maxlen << endl;
			}
		}
	}
	return maxlen;
}


int optimized(vector<int> arr, int n, int k){
	map<int, int> summap;
	int maxlen = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
		if (sum==k) maxlen = max(maxlen, i+1);
		
		int rem = sum-k;
		if(summap.find(rem) != summap.end()){
			maxlen = max(i-summap[rem], maxlen);
		}
		
		if(summap.find(sum) == summap.end()) summap[sum] = i;
	}
	
	return maxlen;
}

int positiveBest(vector<int> arr, int n, int k){
	int i=0, j=0;
	int sum = 0, maxlen = 0;
	while (i<n){
		sum += arr[i];
		while (sum>k && j<=i){
			sum -= arr[j++];
		}
		if (sum == k) maxlen = max(maxlen, i-j+1);
		i++;
	}
	return maxlen;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	cout << positiveBest(arr, n, k) << endl ;

}


