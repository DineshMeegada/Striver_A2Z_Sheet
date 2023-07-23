#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n){
	vector<int> leadArr;
	int max_ele = INT_MIN;
	for (int i=n-1; i>=0; i--){
		if (arr[i] >= max_ele){
			leadArr.push_back(arr[i]);
			max_ele = arr[i];
		}
	}
	
	return leadArr;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	vector<int> leadersArr = leaders(arr, n);
	
	for(int it: leadersArr) cout << it << " ";


}

