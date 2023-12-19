#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int k, vector<int> &heights){
    if (ind == 0) return 0;

    int energy = INT_MAX;
    for (int i=1; i<=k; i++){
        int nind = ind - i;

        if (nind >= 0){
            energy = min(energy, solve(nind, k, heights) + abs(heights[ind]-heights[nind]));
        }
    }

    return energy;
}

int minimizeCost(int n, int k, vector<int> &heights){
    return solve(n-1, k, heights);
}

// Memoization
int solve2(int ind, int k, vector<int> &heights, vector<int> &dp){
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int energy = INT_MAX;
    for (int i=1; i<=k; i++){
        int nind = ind - i;

        if (nind >= 0){
            energy = min(energy, solve2(nind, k, heights, dp) + abs(heights[ind]-heights[nind]));
        }
    }

    return dp[ind] = energy;
}

int minimizeCost2(int n, int k, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return solve2(n-1, k, heights, dp);
}

// Tabulation
int minimizeCost3(int n, int k, vector<int> &heights){
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i=1; i<n; i++){
        int cur = INT_MAX;
        for (int j=1; j<=k; j++){
            int nind = i-j;

            if (nind >= 0)
                cur = min(cur, dp[nind]+abs(heights[i]-heights[nind]));
        }

        dp[i] = cur;
    }

    return dp[n-1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    cout << minimizeCost3(n, k, arr);
    
    
    
    
    return 0;
}