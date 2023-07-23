#include <bits/stdc++.h>
using namespace std;



int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n; 
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
//	set<int> st;
//	for (auto it : arr) st.insert(it);
//	
//	int k = st.size();
//	int i = 0;
//	for (auto it : st){
//		arr[i++] = it;
//	}
//	
//	for(auto it: arr) cout << it << " " ;


	int k = 0;
	for (int i=1; i<n; i++){
		if (arr[i] != arr[k]) arr[++k] = arr[i];
	}
	
	cout << k+1 << endl;
	
	for(auto it : arr) cout << it << " ";
	
	

}


