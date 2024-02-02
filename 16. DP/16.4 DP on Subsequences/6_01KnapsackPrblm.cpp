#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int ind, int cap, vector<int> &wt, vector<int> &val){
	if (ind == 0) {
		if (cap >= wt[0]) return val[0];
		else return 0;
	}

	int notPick = solve1(ind-1, cap, wt, val);
	int pick = 0;
	if (cap >= wt[ind]) pick = val[ind] + solve1(ind-1, cap-wt[ind], wt, val);

	return max(pick, notPick);
}

int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve1(n-1, maxWeight, weight, value);
}

// Memoization
int solve2(int ind, int cap, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
	if (ind == 0) {
		if (cap >= wt[0]) return val[0];
		else return 0;
	}

	if (dp[ind][cap] != -1) return dp[ind][cap];

	int notPick = solve2(ind-1, cap, wt, val, dp);
	int pick = 0;
	if (cap >= wt[ind]) pick = val[ind] + solve2(ind-1, cap-wt[ind], wt, val, dp);

	return dp[ind][cap] = max(pick, notPick);
}

int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve2(n-1, maxWeight, weight, value, dp);
}

// Tabulation
int knapsack3(vector<int> wt, vector<int> val, int n, int maxW) {
	vector<vector<int>> dp(n, vector<int>(maxW+1, 0));
	for (int w=wt[0]; w<=maxW; w++){
		dp[0][w] = val[0];
	}

	for (int ind=1; ind<n; ind++){
		for (int cap=1; cap<=maxW; cap++){
			int notPick = dp[ind-1][cap];
			int pick = 0;
			if (wt[ind] <= cap) pick = val[ind] + dp[ind-1][cap-wt[ind]];

			dp[ind][cap] = max(pick, notPick);

		}
	}

	return dp[n-1][maxW];
}

// Space Optimization - O(2N)
int knapsack4(vector<int> wt, vector<int> val, int n, int maxW) {
	// vector<vector<int>> dp(n, vector<int>(maxW+1, 0));
	vector<int> prev(maxW+1, 0);
	for (int w=wt[0]; w<=maxW; w++){
		prev[w] = val[0];
	}

	for (int ind=1; ind<n; ind++){
		vector<int> cur(maxW+1, 0);
		for (int cap=1; cap<=maxW; cap++){
			int notPick = prev[cap];
			int pick = 0;
			if (wt[ind] <= cap) pick = val[ind] + prev[cap-wt[ind]];

			cur[cap] = max(pick, notPick);
		}

		prev = cur;
	}

	return prev[maxW];
}

// Space Optimization - O(N)
int knapsack5(vector<int> wt, vector<int> val, int n, int maxW) {
	vector<int> prev(maxW+1, 0);
	for (int w=wt[0]; w<=maxW; w++){
		prev[w] = val[0];
	}

	for (int ind=1; ind<n; ind++){
		for (int cap=maxW; cap>=1; cap--){
			int notPick = prev[cap];
			int pick = 0;
			if (wt[ind] <= cap) pick = val[ind] + prev[cap-wt[ind]];

			prev[cap] = max(pick, notPick);
		}
	}

	return prev[maxW];
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}