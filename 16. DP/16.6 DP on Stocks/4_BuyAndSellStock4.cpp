#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int ind, bool buy, int k, vector<int> &prices){
    int n = prices.size();
    if (ind == n || (k==0 && buy)) return 0;

    if (buy) {
        int take = -prices[ind] + solve1(ind+1, false, k-1, prices);
        int notTake = solve1(ind+1, true, k, prices);

        return max(take, notTake);
    } else {
        int take = prices[ind] + solve1(ind+1, true, k, prices);
        int notTake = solve1(ind+1, false, k, prices);

        return max(take, notTake);
    }

    return 0;
}

int maxProfit1(int k, vector<int>& prices) {
    return solve1(0, true, k, prices);
}

// Memoization
int solve2(int ind, bool buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
    int n = prices.size();
    if (ind == n || (k==0 && buy)) return 0;
    if (dp[ind][buy][k] != -1) return dp[ind][buy][k];

    if (buy) {
        int take = -prices[ind] + solve2(ind+1, false, k-1, prices, dp);
        int notTake = solve2(ind+1, true, k, prices, dp);

        return dp[ind][buy][k] = max(take, notTake);
    } else {
        int take = prices[ind] + solve2(ind+1, true, k, prices, dp);
        int notTake = solve2(ind+1, false, k, prices, dp);

        return dp[ind][buy][k] = max(take, notTake);
    }

    return 0;
}

int maxProfit2(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve2(0, true, k, prices, dp);
}

// Tabulation
int maxProfit(int K, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(K+1, 0)));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            for (int k=1; k<=K; k++){
                if (buy) {
                    int take = -prices[ind] + dp[ind+1][0][k];
                    int notTake = dp[ind+1][1][k];

                    dp[ind][buy][k] = max(take, notTake);
                } else {
                    int take = prices[ind] + dp[ind+1][1][k-1];
                    int notTake = dp[ind+1][0][k];

                    dp[ind][buy][k] = max(take, notTake);
                }
            }
        }
    }

    return dp[0][1][K];
}

// Space Optimization
int maxProfit(int K, vector<int>& prices) {
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(K+1, 0)));
    vector<vector<int>> after(2, vector<int> (K+1, 0)), cur(2, vector<int> (K+1, 0));

    for (int ind=n-1; ind>=0; ind--){
        for (int buy=0; buy<=1; buy++){
            for (int k=1; k<=K; k++){
                if (buy) {
                    int take = -prices[ind] + after[0][k];
                    int notTake = after[1][k];

                    cur[buy][k] = max(take, notTake);
                } else {
                    int take = prices[ind] + after[1][k-1];
                    int notTake = after[0][k];

                    cur[buy][k] = max(take, notTake);
                }
            }
        }

        after = cur;
    }

    return after[1][K];
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}