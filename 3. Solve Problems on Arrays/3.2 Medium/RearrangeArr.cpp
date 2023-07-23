#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n){
	vector<int> posArr, negArr;
	
	for (int i=0; i<n; i++){
		if (arr[i]>0) posArr.push_back(arr[i]);
		else negArr.push_back(arr[i]);
	}
	
	for(int i=0; i<n/2; i++){
		arr[i*2] = posArr[i];
		arr[i*2+1] = negArr[i];
	}
}

vector<int> rearrangeOpt(int arr[], int n){
	vector<int> resArr(n, 0);
	int pos = 0, neg = 0;
	for(int i=0; i<n; i++) {
		if (arr[i] > 0) resArr[pos++*2] = arr[i];
		else resArr[neg++*2+1] = arr[i];
	}
	return resArr;
}

void rearrUnequalSigns(int arr[], int n){
	vector<int> neg, pos;
	for (int i=0; i<n; i++){
		if (arr[i] < 0) neg.push_back(arr[i]);
		else pos.push_back(arr[i]);
	}
	
	if (neg.size() > pos.size()){
		for (int i=0; i<pos.size(); i++){
			arr[i*2] = pos[i];
			arr[i*2+1] = neg[i];
		}
		
		int ind = 2*pos.size();
		for (int i=pos.size(); i<neg.size(); i++){
			arr[ind++] = neg[i];
		}
	} else {
		for (int i=0; i<neg.size(); i++){
			arr[i*2] = pos[i];
			arr[i*2+1] = neg[i];
		}
		
		int ind = 2*neg.size();
		for (int i=neg.size(); i<pos.size(); i++){
			arr[ind++] = pos[i];
		}
	}
	
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	for(auto it: arr) cout << it << " ";
	
	rearrUnequalSigns(arr, n);
	cout << endl;
	
	for(auto it: arr) cout << it << " ";
	


}

