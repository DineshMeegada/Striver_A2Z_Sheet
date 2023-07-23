#include <bits/stdc++.h>
using namespace std;

vector<int> majorEle(vector<int> arr, int n){
	vector<int> res;
	unordered_map<int, int> freq;
	
	for (int i=0; i<n; i++){
		freq[arr[i]]++;
	} 
	
	for (auto it: freq){
		cout << it.first << " - " << it.second << endl;
		if (it.second > n/3) res.push_back(it.first);
	}
	
	return res;
}

vector<int> majorEleOpt(vector<int> arr, int n){
	int ele1 = 0, ele2 = 0, cnt1 = 0, cnt2 = 0;
	
	for (int i=0; i<n; i++){
		if (arr[i]==ele1) cnt1++;
		else if (arr[i]==ele2) cnt2++;
		else if (cnt1 == 0) {
			ele1 = arr[i];
			cnt1++;
		}
		else if (cnt2 == 0){
			ele2 = arr[i];
			cnt2++;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}
	
	vector<int> res;
	int count1 = 0, count2 = 0;
	for(int i=0; i<n; i++){
		if (arr[i] == ele1) count1++;
		else if (arr[i] == ele2) count2++;
	}
	
	if (count1>n/3) res.push_back(ele1);
	if (count2>n/3) res.push_back(ele2);
	
	return res;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;

	vector<int> res = majorEleOpt(arr, n);
	
	for (auto it: res) cout << it << " ";


}


