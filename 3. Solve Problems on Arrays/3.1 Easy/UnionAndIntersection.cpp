#include <bits/stdc++.h>
using namespace std;

vector<int> unionArr(vector<int> arr1, vector<int> arr2, int m, int n){
	
	vector<int> res;
	int i=0, j=0;
	
	while (i<m && j<n){
		if(arr1[i]<arr2[j]){
			if(res.size()==0 || arr1[i]>res.back()){
				res.push_back(arr1[i]);
			}
			i++;
		}
		else{
			if(arr2[j]>res.back()){
				res.push_back(arr2[j]);
			}
			j++;
		}
	}
	
	while (i<m){
		if(res.size()==0 || arr1[i]>res.back()){
			res.push_back(arr1[i]);
		}
		i++;
	}
	
	while (j<n){
		if(res.size()==0 || arr2[j]>res.back()){
			res.push_back(arr2[j]);
		}
		j++;
	}
	
	return res;
}

vector<int> intersectArr(vector<int> arr1, vector<int> arr2, int m, int n){
	vector<int> res;
	int i=0, j=0;
	
	while(i<m && j<n){
		if(arr1[i]<arr2[j]) i++;
		else if(arr2[j]<arr1[i]) j++;
		else{
			res.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	
	return res;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n;
	cin >> m >> n;
	
	vector<int> arr1(m) ;
	vector<int> arr2(m) ;
		
	for (int i=0; i<m; i++) cin >> arr1[i] ;
	for (int i=0; i<n; i++) cin >> arr2[i] ;
	
	vector<int> result = intersectArr(arr1, arr2, m, n);
	
	for (auto it: result) cout << it << " ";
 
}


