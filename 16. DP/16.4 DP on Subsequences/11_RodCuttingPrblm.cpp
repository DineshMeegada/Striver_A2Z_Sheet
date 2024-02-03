#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int len, vector<int> &price){
	if (len == 0) return 0;
	if (ind == 0) return price[0]*len;

	int notTake = solve(ind-1, len, price);
	int take = 0;
	if (ind+1<=len) take = price[ind] + solve(ind, len-ind-1, price);

	return max(take, notTake);
}

int cutRod(vector<int> &price, int n){
	return solve(n-1, n, price);
}

// /Memoization
int solve2(int ind, int len, vector<int> &price, vector<vector<int>> &dp){
	if (len == 0) return 0;
	if (ind == 0) return price[0]*len;

    if (dp[ind][len] != -1) return dp[ind][len];

	int notTake = solve2(ind-1, len, price, dp);
	int take = 0;
	if (ind+1<=len) take = price[ind] + solve2(ind, len-ind-1, price, dp);

	return dp[ind][len] = max(take, notTake);
}

int cutRod2(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return solve2(n-1, n, price, dp);
}

// Tabulation
int cutRod3(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
	for (int i=0; i<=n; i++){
		dp[0][i] = price[0]*i;
	}

	for (int ind=1; ind<n; ind++){
		for (int len=0; len<=n; len++){
			int notTake = dp[ind-1][len];
			int take = 0;
			if (ind+1 <= len) take = price[ind] + dp[ind][len-ind-1];

			dp[ind][len] = max(take, notTake);
		}
	}


	return dp[n-1][n];
}

// Space Optimization - O(2N)
int cutRod4(vector<int> &price, int n){
    vector<int> prev(n+1, 0);
	for (int i=0; i<=n; i++){
		prev[i] = price[0]*i;
	}

	for (int ind=1; ind<n; ind++){
        vector<int> cur(n+1, 0);
		for (int len=0; len<=n; len++){
			int notTake = prev[len];
			int take = 0;
			if (ind+1 <= len) take = price[ind] + cur[len-ind-1];

			cur[len] = max(take, notTake);
		}

        prev = cur;
	}

	return prev[n];
}

// Space Optimization - O(N)
int cutRod5(vector<int> &price, int n){
    vector<int> prev(n+1, 0);
	for (int i=0; i<=n; i++){
		prev[i] = price[0]*i;
	}

	for (int ind=1; ind<n; ind++){
        // vector<int> cur(n+1, 0);
		for (int len=0; len<=n; len++){
			int notTake = prev[len];
			int take = 0;
			if (ind+1 <= len) take = price[ind] + prev[len-ind-1];

			prev[len] = max(take, notTake);
		}

        // prev = cur;
	}

	return prev[n];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}