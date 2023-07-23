#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	// int array
	
	/*int n;
	cin >> n;
	
	int arr[n];	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	//pre compute
	int hash[10] = {0};
	
	for (int i=0; i<n; i++){
		hash[arr[i]] += 1;
	}
	
	int q; 
	cin >> q;
	while (q--){
		int ele;
		cin >> ele;
		cout << hash[ele] << endl;
	}*/
	
	
	// string 
	
	/*string s; 
	cin >> s;
	
	int hash[26] = {0};
	for (int i=0; i<s.size(); i++){
		hash[s[i] - 'a'] += 1;
	}
	
	int q;
	cin >> q;
	
	while (q--){
		char ele;
		cin >> ele;
		cout << hash[ele - 'a'] << endl;
	}*/
	
	
	// map
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	unordered_map<int, int> mpp ;
	for (int i=0; i<n; i++){
		mpp[arr[i]]++;
	}
	
//	int q; 
//	cin >> q;
//	while (q--){
//		int num;
//		cin >> num;
//		cout << mpp[num] << endl;
//	}
	
	int maxi = arr[0], mini = arr[0];
	for (auto it : mpp){
		cout << it.first << "->" << it.second << endl;
		if (it.second>mpp[maxi]) maxi = it.first;
		if (it.second<mpp[mini]) mini = it.first;
	}
	
	cout << "Max frequency element : " << maxi << endl;
	cout << "Min frequency element : " << mini << endl;
	
}


