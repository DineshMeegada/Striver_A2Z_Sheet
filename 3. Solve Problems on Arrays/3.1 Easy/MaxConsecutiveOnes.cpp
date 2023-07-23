#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	int maxi=0 , cnt=0 ;
	for (int i=0; i<n; i++){
		if (arr[i] == 0) cnt = 0;
		else cnt++;
		maxi = max(maxi, cnt);
	}
	
	cout << maxi;
	
}


