#include <bits/stdc++.h>
using namespace std;

int longestSeqOpt(vector<int> arr, int n){
	unordered_set<int> unq;
	for(int it: arr) unq.insert(it);
	
	int longest = 1;
	for (int it: unq) {
		if (unq.find(it-1) == unq.end()){
			int cnt = 1;
			int num = it;
			while(unq.find(num+1) != unq.end()){
				cnt++;
				num++;
			}
			longest = max(longest, cnt);
		}
	}
	
	return longest;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;
	
	cout << longestSeqOpt(arr, n) ;



}

