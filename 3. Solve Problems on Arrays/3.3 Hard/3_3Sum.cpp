#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute3sum(vector<int> arr, int n, int target){
	
	set<vector<int>> st;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			for (int k=0; k<n; k++) {
				if (arr[i] + arr[j] + arr[k] == target){
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
			}
		}
	}
	
	vector<vector<int>> ans (st.begin(), st.end());
	return ans;
}

vector<vector<int>> better3sum(vector<int> arr, int n, int target){
	set<vector<int>> st;
	for (int i=0; i<n; i++) {
		set<int> hashSet;
		for (int j=i+1; j<n; j++){
			int third = -(arr[i] + arr[j]);
			if (hashSet.find(third) != hashSet.end()) {
				vector<int> temp = {arr[i], arr[j], third};
				sort(temp.begin(), temp.end());
				st.insert(temp);
			}
			hashSet.insert(arr[j]);
		}
	}
	
	vector<vector<int>> ans (st.begin(), st.end());
	return ans;
}

vector<vector<int>> best3sum(vector<int> arr, int n, int target){
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	
	int i=0;
	while(i<n){
		int sum = arr[i];
		int j=i+1, k=n-1;
		while (j<k){
			sum = arr[i] + arr[j] + arr[k];
			if (sum < target) {
				j++;
				while(arr[j]==arr[j-1]) j++;
			}else if (sum > target) {
				k--;
				while(arr[k]==arr[k+1]) k--;
			}else {
				vector<int> temp = {arr[i], arr[j], arr[k]};
				ans.push_back(temp);
			}
		}
		i++;
		while(arr[i]==arr[i-1]) i++;
	}
	
	return ans;
}

vector<vector<int>> triplets(vector<int> arr, int n){
	vector<vector<int>> res;
	sort(arr.begin(), arr.end());
	
	for (int i=0; i<n; i++){
		if (i==0 || (i>0 && arr[i]!=arr[i-1])){
			int low = i+1, high = n-1, sum = 0-arr[i];
			while (low < high){
				if(arr[low] + arr[high] == sum){
					vector<int> temp = {arr[i], arr[low], arr[high]};
					res.push_back(temp);
					
					while (low<high && arr[low]==arr[low+1]) low++;
					while (high>low && arr[high]==arr[high-1]) high--;
					
					low++; high--;
				}
				else if (arr[low] + arr[high] < sum) low++;
				else high--;
			}
		}
	}
	
	return res;
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, target;
	cin >> n >> target;

	vector<int> arr(n);
	for (int i=0; i<n; i++) cin >> arr[i] ;

	vector<vector<int>> res = best3sum(arr, n, target);
	int sz = res.size();
	
	for(auto it: res){
		for (int j=0; j<3; j++) cout << it[j] << " ";
		cout << endl;
	}
	

}


