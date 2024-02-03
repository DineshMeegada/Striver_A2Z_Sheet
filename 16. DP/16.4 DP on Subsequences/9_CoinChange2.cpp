#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int amt, vector<int> &coins){
    if (ind==0) {
        if (amt%coins[0]==0) return 1;
        return 0;
    }

    int notTake = solve(ind-1, amt, coins);
    int take = 0;
    if (coins[ind]<=amt) take = solve(ind, amt-coins[ind], coins);

    return take + notTake;
}    

int change(int amount, vector<int>& coins) {
    int n = coins.size();

    return solve(n-1, amount, coins);
}


// Memoization
int solve2(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp){
    if (ind==0) {
        if (amt%coins[0]==0) return 1;
        return 0;
    }

    if (dp[ind][amt] != -1) return dp[ind][amt];

    int notTake = solve2(ind-1, amt, coins, dp);
    int take = 0;
    if (coins[ind]<=amt) take = solve2(ind, amt-coins[ind], coins, dp);

    return dp[ind][amt] = take + notTake;
}    

int change2(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));

    return solve2(n-1, amount, coins, dp);
}

// Tabulation
int change3(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    for(int i=0; i<=amount; i++){
        if (i%coins[0]==0) dp[0][i] = 1;
    }

    for (int ind=1; ind<n; ind++){
        for (int amt=0; amt<=amount; amt++){
            int notTake = dp[ind-1][amt];
            int take = 0;
            if (coins[ind]<=amt) take = dp[ind][amt-coins[ind]];

            dp[ind][amt] = take + notTake;
        }
    }

    return dp[n-1][amount];
}

// Space Optimization
int change4(int amount, vector<int> &coins){
    int n = coins.size();
    vector<int> prev(amount+1, 0);

    for (int i=0; i<=amount; i++){
        if (i%coins[0] == 0) prev[i] = 1;
    }

    for (int ind=1; ind<n; ind++){
        vector<int> cur(amount+1, 0);
        for (int amt=0; amt<=amount; amt++){
            int notTake = prev[amt];
            int take = 0;
            if (coins[ind]<=amt) take = cur[amt-coins[ind]];

            cur[amt] = take + notTake;
        }

        prev = cur;
    }

    return prev[amount];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}