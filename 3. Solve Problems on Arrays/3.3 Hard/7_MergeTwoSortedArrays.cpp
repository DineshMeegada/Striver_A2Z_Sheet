#include <bits/stdc++.h>
using namespace std;

void mergeArraysBrute(vector<int>& arr1, vector<int>& arr2){
	int m = arr1.size();
	int n = arr2.size();
	vector<int> temp;
	
	int p1 = 0, p2 = 0;
	while(p1<m && p2<n){
		if (arr1[p1]<arr2[p2]) temp.push_back(arr1[p1++]);
		else temp.push_back(arr2[p2++]);
	}
	
	while (p1<m) temp.push_back(arr1[p1++]);
	while (p2<n) temp.push_back(arr2[p2++]);
	
	for (int i=0; i<m; i++){
		arr1[i] = temp[i];
	}
	
	for (int j=m; j<m+n; j++){
		arr2[j-m] = temp[j];
	}
}

void mergeArrays(vector<int>& arr1, vector<int>& arr2){
	int m = arr1.size();
	int n = arr2.size();
	for(int i=0; i<m; i++){
		if (arr1[i] > arr2[0]){
			int temp = arr1[i];
			arr1[i] = arr2[0];
			arr2[0] = temp;
		}
		
		int j, first = arr2[0];
		for (j=1; j<n && arr2[j]<first; j++){
			arr2[j-1] = arr2[j];
		}
		arr2[j-1] = first;
	}
}

void mergeArrs(vector<int>& arr1, vector<int>& arr2) {
	int m = arr1.size();
	int n = arr2.size();

	int left = m-1, right = 0;
	while (left >= 0 && right < n) {
		if (arr1[left] > arr2[right]) swap(arr1[left], arr2[right]);
		else break;
		left--, right++;
	}

	sort (arr1.begin(), arr1.end());
	sort (arr2.begin(), arr2.end());

}

void gapMerge(vector<int>& arr1, vector<int>& arr2){
	int m = arr1.size();
	int n = arr2.size();
	
	int gap = (m+n)/2;
	while (gap > 0){
		int i = 0, j = gap;
		
		if (j<n && arr1[j]<arr1[i]) swap(arr1[i], arr1[j]);
		else if (j<n && i<m && arr1[i]<arr2[j]) swap(arr1[i], arr2[j]);
		else if (j<n && i>m && arr2[i]<arr2[j]) swap(arr2[i], arr2[j]);
		i++; j++;
		
		if (gap == 1) gap = 0;
		else ceil((float) gap /2);
	}
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m >> n;

	vector<int> arr1(m);
	for (int i=0; i<m; i++) cin >> arr1[i] ;
	
	vector<int> arr2(n);
	for (int i=0; i<n; i++) cin >> arr2[i] ;

	for (int it: arr1) cout << it << " ";
	cout << endl;
	for (int it: arr2) cout << it << " ";
	
	cout << endl << endl;
	mergeArrs(arr1, arr2);
	for (int it: arr1) cout << it << " ";
	cout << endl;
	for (int it: arr2) cout << it << " ";


}


