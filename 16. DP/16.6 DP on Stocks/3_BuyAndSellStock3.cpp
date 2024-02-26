#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, bool buy, int k, vector<int> &prices){
    int n = prices.size();
    if (ind == n || (k==0 && buy)) return 0;

    if (buy) {
        int take = -prices[ind] + solve(ind+1, false, k-1, prices);
        int notTake = solve(ind+1, true, k, prices);

        return max(take, notTake);
    } else {
        int take = prices[ind] + solve(ind+1, true, k, prices);
        int notTake = solve(ind+1, false, k, prices);

        return max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices) {
    return solve(0, true, 2, prices);
}

// Memoization
int solve(int ind, bool buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
    int n = prices.size();
    if (ind == n || (k==0 && buy)) return 0;
    if (dp[ind][buy][k] != -1) return dp[ind][buy][k];

    if (buy) {
        int take = -prices[ind] + solve(ind+1, false, k-1, prices, dp);
        int notTake = solve(ind+1, true, k, prices, dp);

        return dp[ind][buy][k] = max(take, notTake);
    } else {
        int take = prices[ind] + solve(ind+1, true, k, prices, dp);
        int notTake = solve(ind+1, false, k, prices, dp);

        return dp[ind][buy][k] = max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size(), k = 2;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve(0, true, 2, prices, dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size(), mT = 2;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(mT+1, 0)));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            for (int k=1; k<=mT; k++){
                if (buy){
                    int take = prices[ind] + dp[ind+1][0][k-1];
                    int notTake = dp[ind+1][1][k];
                    dp[ind][buy][k] = max(take, notTake);
                } else {
                    int take = -prices[ind] + dp[ind+1][1][k];
                    int notTake = dp[ind+1][0][k];
                    dp[ind][buy][k] = max(take, notTake);
                }
            }
        }
    }

    return dp[0][0][mT];
}

// Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size(), mT = 2;
    vector<vector<int>> ahead(2, vector<int> (mT+1, 0)), cur(2, vector<int> (mT+1, 0));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            for (int k=1; k<=mT; k++){
                if (buy){
                    int take = prices[ind] + ahead[0][k-1];
                    int notTake = ahead[1][k];
                    cur[buy][k] = max(take, notTake);
                } else {
                    int take = -prices[ind] + ahead[1][k];
                    int notTake = ahead[0][k];
                    cur[buy][k] = max(take, notTake);
                }
            }
        }

        ahead = cur;
    }

    return ahead[0][mT];

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}