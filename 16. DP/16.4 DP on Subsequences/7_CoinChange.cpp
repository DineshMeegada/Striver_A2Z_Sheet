#include <bits/stdc++.h>
using namespace std;

// Recursion 1
int solve(int level, int amount, vector<int> &coins){
    int n = coins.size();
    if (amount==0) return level;

    int ans = INT_MAX;
    for (int i=0; i<n; i++){
        if (coins[i] <= amount) 
            ans = min(ans, solve(level+1, amount-coins[i], coins));
    }

    return ans;
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans = solve(0, amount, coins);
    
    return (ans==INT_MAX) ? -1 : ans;
}

// Recursion 2
int solve1(int ind, int amount, vector<int> &coins){
    if (ind == 0) {
        if (amount % coins[ind] == 0) return amount/coins[ind];
        else return 1e9;
    }

    int notTake = solve1(ind-1, amount, coins);
    int take = 1e9;
    if (amount >= coins[ind]) take = 1 + solve1(ind, amount-coins[ind], coins);

    return min(notTake, take);
}

int coinChange1(vector<int> &coins, int amount){
    int n = coins.size();
    int ans = solve1(n-1, amount, coins);

    return (ans==1e9) ? -1 : ans;
}

// Memoization
int solve2(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if (ind == 0) {
        if (amount % coins[ind] == 0) return amount/coins[ind];
        else return 1e9;
    }

    if (dp[ind][amount] != -1) return dp[ind][amount];

    int notTake = solve2(ind-1, amount, coins, dp);
    int take = 1e9;
    if (amount >= coins[ind]) take = 1 + solve2(ind, amount-coins[ind], coins, dp);

    return dp[ind][amount] = min(notTake, take);
}

int coinChange2(vector<int> &coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    int ans = solve2(n-1, amount, coins, dp);

    return (ans==1e9) ? -1 : ans;
}

// Tabulation
int coinChange3(vector<int> &coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));
    for (int i=0; i<=amount; i++){
        if (i%coins[0] == 0) dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9;
    }

    for (int ind=1; ind<n; ind++){
        for (int amt=0; amt<=amount; amt++){
            int notTake = dp[ind-1][amt];
            int take = 1e9;
            if (coins[ind] <= amt) take = 1 + dp[ind][amt-coins[ind]];

            dp[ind][amt] = min(take, notTake);
        }
    }

    return (dp[n-1][amount]>=1e9) ? -1 : dp[n-1][amount];
}

// Space Optimization
int coinChange4(vector<int> &coins, int amount){
    int n = coins.size();
    vector<int> prev(amount+1, 0);
    for (int i=0; i<=amount; i++){
        if (i%coins[0] == 0) prev[i] = i/coins[0];
        else prev[i] = 1e9;
    }

    for (int ind=1; ind<n; ind++){
        vector<int> cur(amount+1, 0);
        for (int amt=0; amt<=amount; amt++){
            int notTake = prev[amt];
            int take = 1e9;
            if (coins[ind] <= amt) take = 1 + cur[amt-coins[ind]];

            cur[amt] = min(take, notTake);
        }
        prev = cur;
    }


    return (prev[amount]>=1e9) ? -1 : prev[amount];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}