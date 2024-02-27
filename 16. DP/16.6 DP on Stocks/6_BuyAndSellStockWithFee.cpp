#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int ind, int buy, vector<int> &prices, int &fee){
    int n = prices.size();
    if (ind == n) return 0;
    
    if (buy){
        int take = -prices[ind] + solve(ind+1, 0, prices, fee);
        int notTake = solve(ind+1, 1, prices, fee);

        return max(take, notTake);
    } else {
        int take = prices[ind] - fee + solve(ind+1, 1, prices, fee);
        int notTake = solve(ind+1, 0, prices, fee);

        return max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices, int fee) {
    return solve(0, 1, prices, fee);
}

// Memoization
int solve(int ind, int buy, vector<int> &prices, int &fee, vector<vector<int>> &dp){
    int n = prices.size();
    if (ind == n) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];
    
    if (buy){
        int take = -prices[ind] + solve(ind+1, 0, prices, fee, dp);
        int notTake = solve(ind+1, 1, prices, fee, dp);

        return dp[ind][buy] = max(take, notTake);
    } else {
        int take = prices[ind] - fee + solve(ind+1, 1, prices, fee, dp);
        int notTake = solve(ind+1, 0, prices, fee, dp);

        return dp[ind][buy] = max(take, notTake);
    }

    return 0;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return solve(0, 1, prices, fee, dp);
}

// Tabulation
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = -prices[ind] + dp[ind+1][0];
                int notTake = dp[ind+1][1];

                dp[ind][buy] = max(take, notTake);
            } else {
                int take = prices[ind] - fee + dp[ind+1][1];
                int notTake = dp[ind+1][0];

                dp[ind][buy] = max(take, notTake);
            }
        }
    }

    return dp[0][1];
}

// Space Optimization
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> front(2, 0), cur(2, 0);

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            if (buy){
                int take = -prices[ind] + front[0];
                int notTake = front[1];

                cur[buy] = max(take, notTake);
            } else {
                int take = prices[ind] - fee + front[1];
                int notTake = front[0];

                cur[buy] = max(take, notTake);
            }
        }

        front = cur;
    }

    return front[1];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}