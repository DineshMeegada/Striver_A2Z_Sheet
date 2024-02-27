#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int buy, vector<int> &prices){
    int n = prices.size();
    if (ind >= n) return 0;

    if (buy){
        int take = -prices[ind] + solve(ind+1, 0, prices);
        int notTake = solve(ind+1, 1, prices);

        return max(take, notTake);
    } else{
        int take = prices[ind] + solve(ind+2, 1, prices);
        int notTake = solve(ind+1, 0, prices);

        return max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices) {
    return solve(0, 1, prices);
}

// Memoization
int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    int n = prices.size();
    if (ind >= n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy){
        int take = -prices[ind] + solve(ind+1, 0, prices, dp);
        int notTake = solve(ind+1, 1, prices, dp);

        return dp[ind][buy] = max(take, notTake);
    } else{
        int take = prices[ind] + solve(ind+2, 1, prices, dp);
        int notTake = solve(ind+1, 0, prices, dp);

        return dp[ind][buy] = max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int> (2, -1));
    return solve(0, 1, prices, dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int> (2, 0));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = -prices[ind] + dp[ind+1][0];
                int notTake = dp[ind+1][1];

                dp[ind][buy] = max(take, notTake);
            } else{
                int take = prices[ind] + dp[ind+2][1];
                int notTake = dp[ind+1][0];

                dp[ind][buy] = max(take, notTake);
            }
        }
    }

    return dp[0][1];

}

// Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> cur(2, 0), front1(2, 0), front2(2, 0);

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = -prices[ind] + front1[0];
                int notTake = front1[1];

                cur[buy] = max(take, notTake);
            } else{
                int take = prices[ind] + front2[1];
                int notTake = front1[0];

                cur[buy] = max(take, notTake);
            }
        }

        front2 = front1;
        front1 = cur;
    }

    return front1[1];

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}