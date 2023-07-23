#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumBrute(vector<int> arr, int n, int target){
	set<vector<int>> sv;
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			for (int k=j+1; k<n; k++){
				auto rem = (long long) target - (long long) nums[i] - (long long) nums[j] - (long long) nums[k];
				if(binary_search(rem)){
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[k]);
					v.push_back(rem);
					sort(v.begin(), v.end());
					sv.insert(v);
				} 
			}
		}
	}
	
	vector<vector<int>> res (sv.begin(), sv.end());
	return res;
	
}

vector<vector<int>> fourSumOpt(vector<int> arr, int n, int target){
	vector<vector<int>> res;
	if(arr.empty()) return res;
	sort(arr.begin(), arr.end());
	
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			long long rem = (long long)target - arr[i] - arr[j];
			int left = j+1, right = n-1;
			
			while (left < right) {
				int two_sum = arr[left] + arr[right];
				if (two_sum < rem) left++;
				else if (two_sum > rem) right--;
				else {
					vector<int> v = {arr[i], arr[j], arr[left], arr[right]};
					res.push_back(v);
					
					while(left<right && arr[left]==v[2]) left++;
					while(left<right && arr[right]==v[3]) right--;
				}
			}
			while (j+1<n && arr[j]==arr[j+1]) j++;
		}
		while (i+1<n && arr[i]==arr[i+1]) i++;
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




}


