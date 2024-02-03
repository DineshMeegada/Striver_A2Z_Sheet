#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int cap, vector<int> &wt, vector<int> &val){
    if (ind == 0) {
        return (cap/wt[0])*val[0];
    }

    int notTake = solve(ind-1, cap, wt, val);
    int take = 0;
    if (wt[ind] <= cap) take = val[ind] + solve(ind, cap-wt[ind], wt, val);

    return max(take, notTake);
}

int unboundedKnapsack(int n, int cap, vector<int> &val, vector<int> &weight){
    return solve(n-1, cap, weight, val);
}

// Memoization
int solve2(int ind, int cap, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
    if (ind == 0) {
        return (cap/wt[0])*val[0];
    }

    if (dp[ind][cap] != -1) return dp[ind][cap];

    int notTake = solve2(ind-1, cap, wt, val, dp);
    int take = 0;
    if (wt[ind] <= cap) take = val[ind] + solve2(ind, cap-wt[ind], wt, val, dp);

    return dp[ind][cap] = max(take, notTake);
}

int unboundedKnapsack2(int n, int cap, vector<int> &val, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(cap+1, -1));
    return solve2(n-1, cap, weight, val, dp);
}

// Tabulation
int unboundedKnapsack3(int n, int capacity, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    for (int i=0; i<=capacity; i++){
        dp[0][i] = (i/wt[0])*val[0];
    }

    for (int ind=1; ind<n; ind++){
        for (int cap=0; cap<=capacity; cap++){
            int notTake = dp[ind-1][cap];
            int take = 0;
            if (wt[ind] <= cap) take = val[ind] + dp[ind][cap-wt[ind]];

            dp[ind][cap] = max(take, notTake);
        }
    }

    return dp[n-1][capacity];
}

// Space Optimization - O(2N)
int unboundedKnapsack3(int n, int capacity, vector<int> &val, vector<int> &wt){
    vector<int> prev(capacity+1, 0);
    for (int i=0; i<=capacity; i++){
        prev[i] = (i/wt[0])*val[0];
    }

    for (int ind=1; ind<n; ind++){
        vector<int> cur(capacity+1, 0);
        for (int cap=0; cap<=capacity; cap++){
            int notTake = prev[cap];
            int take = 0;
            if (wt[ind] <= cap) take = val[ind] + cur[cap-wt[ind]];

            cur[cap] = max(take, notTake);
        }
        prev = cur;
    }

    return prev[capacity];
}

// Space Optimization - O(N)
int unboundedKnapsack4(int n, int capacity, vector<int> &val, vector<int> &wt){
    vector<int> prev(capacity+1, 0);
    for (int i=0; i<=capacity; i++){
        prev[i] = (i/wt[0])*val[0];
    }

    for (int ind=1; ind<n; ind++){
        for (int cap=0; cap<=capacity; cap++){
            int notTake = prev[cap];
            int take = 0;
            if (wt[ind] <= cap) take = val[ind] + prev[cap-wt[ind]];

            prev[cap] = max(take, notTake);
        }
    }

    return prev[capacity];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}