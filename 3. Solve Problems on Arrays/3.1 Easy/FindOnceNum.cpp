#include <bits/stdc++.h>
using namespace std;

int usingmap(vector<int> arr, int n){
	map<int, int> mpp;
	
	for (int i=0; i<n; i++){
		mpp[arr[i]]++;
	}
	
	for (auto it: mpp) {
		if (it.second == 1) return it.first;
	}
}

int usingxor(vector<int> arr, int n){
	int xor1 = 0;
	for (int i=0; i<n; i++) xor1 = xor1^arr[i];
	return xor1;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int num = usingxor(arr, n);
	cout << num ;

}


