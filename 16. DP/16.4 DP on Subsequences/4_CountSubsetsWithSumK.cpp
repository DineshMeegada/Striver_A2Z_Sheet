#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int ind, int target, vector<int> &arr){
	if (target == 0) return 1;
	if (ind == 0) return target==arr[ind];

	int notTaken = solve1(ind-1, target, arr);
	int taken = 0;
	if (arr[ind] <= target) taken = solve1(ind-1, target-arr[ind], arr);

	return notTaken+taken;
}

int findWays(vector<int>& arr, int k) {
	int n = arr.size();
	
	return solve1(n-1, k, arr);
}

// Memoization
int solve2(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	if (target == 0) return 1;
	if (ind == 0) return (target==arr[ind]) ? 1 : 0;

	if (dp[ind][target] != -1) return dp[ind][target];

	int notTaken = solve2(ind-1, target, arr, dp);
	int taken = 0;
	if (arr[ind] <= target) taken = solve2(ind-1, target-arr[ind], arr, dp);

	return dp[ind][target] = notTaken+taken;
}


int findWays2(vector<int>& arr, int k) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	
	return solve2(n-1, k, arr, dp);
}

// Tabulation
int findWays3(vector<int> &arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));

	for (int i=0; i<n; i++){
		dp[i][0] = 1;
	}
	dp[0][arr[0]] = 1;

	for (int ind=1; ind<n; ind++){
		for (int target=1; target<=k; target++){
			int notTaken = dp[ind-1][target];
			int taken = 0;
			if(arr[ind]<=target) taken = dp[ind-1][target-arr[ind]];

			dp[ind][target] = taken + notTaken;
		}
	}

	return dp[n-1][k];
}

// Space Optimization
int findWays4(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> prev(k+1, 0);

	prev[0] = 1;
	if (arr[0] <= k) prev[arr[0]] = 1;

	for (int ind=1; ind<n; ind++){
		vector<int> cur(k+1, 0);
		cur[0] = 1;
		for (int target=1; target<=k; target++){
			int notTake = prev[target];
			int take = 0;
			if (arr[ind] <= target) take = prev[target-arr[ind]];

			cur[target] = take + notTake;
		}

		prev = cur;
	}

	return prev[k];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}