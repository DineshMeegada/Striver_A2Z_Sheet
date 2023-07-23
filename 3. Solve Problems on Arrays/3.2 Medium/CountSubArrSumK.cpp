#include <bits/stdc++.h>
using namespace std;

int subArrCount(vector<int> arr, int n, int k){
	int count = 0, sum = 0;
	unordered_map<int, int> subsums;
	subsums[sum]++;
	for (int i=0; i<n; i++){
		sum += arr[i];
		count += subsums[sum-k] ;
		subsums[sum]++;
	}
	return count;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k ;

	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;

	int count = subArrCount(arr, n, k) ;
	cout << count ;


}


