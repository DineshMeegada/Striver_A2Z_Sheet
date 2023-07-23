#include <bits/stdc++.h>
using namespace std;

void defaultlexi(vector<int>& nums){
	next_permutation(nums.begin(), nums.end());
}

vector<int> lexiOpt(vector<int> nums, int n){
	int ind = -1 ;
	for (int i=n-2; i>=0; i--){
		if (nums[i]<nums[i+1]){
			ind = i;
			break;
		}
	}
	
	if(ind == -1){
		reverse(nums.begin(), nums.end());
		return nums;
	}
	
	for(int i=n-1; i>ind; i--){
		if (nums[i]>nums[ind]){
			swap(nums[i], nums[ind]);
			break;
		}
	}
	
	reverse(nums.begin() + ind, nums.end());
	return nums;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> nums(n);
	for (int i=0; i<n; i++) cin >> nums[i];
	
	for(int it: nums) cout << it << " "; 
	
	defaultlexi(nums);
	
	cout << endl << endl;
	for(int it: nums) cout << it << " "; 

	vector<int> numsArr = lexiOpt(nums, n);
	
	cout << endl << endl;
	for(int it: numsArr) cout << it << " "; 



}

