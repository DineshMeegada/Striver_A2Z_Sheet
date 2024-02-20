#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int ind, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp){
    if (ind == n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy){
        int take = -prices[ind] + solve(ind+1, false, prices, n, dp);
        int notTake = solve(ind+1, true, prices, n, dp);

        return dp[ind][buy] = max(take, notTake);
    } else {
        int take = prices[ind] + solve(ind+1, true, prices, n, dp);
        int notTake = solve(ind+1, false, prices, n, dp);

        return dp[ind][buy] = max(take, notTake);
    }

    return -1;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return solve(0, true, prices, n, dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    dp[n][0] = dp[n][1] = 0;

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = prices[ind] + dp[ind+1][0];
                int notTake = dp[ind+1][1];

                dp[ind][buy] = max(take, notTake);
            } else {
                int take = -prices[ind] + dp[ind+1][1];
                int notTake = dp[ind+1][0];

                dp[ind][buy] = max(take, notTake);
            }
        }
    }

    return dp[0][0];
}

// Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<int> ahead(2, 0), cur(2, 0);

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = prices[ind] + ahead[0];
                int notTake = ahead[1];

                cur[buy] = max(take, notTake);
            } else {
                int take = -prices[ind] + ahead[1];
                int notTake = ahead[0];

                cur[buy] = max(take, notTake);
            }
        }

        ahead = cur;
    }

    return ahead[0];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}