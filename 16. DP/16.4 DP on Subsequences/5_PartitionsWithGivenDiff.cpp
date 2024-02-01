#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// Memoization
int count(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
        if (sum==0 && arr[0]==0) return 2;
        else if (sum==0 || sum==arr[0]) return 1;
        return 0;
    }

    if (dp[ind][sum] != -1) return dp[ind][sum];

    int notTake = count(ind-1, sum, arr, dp);
    int take = 0;
    if (arr[ind] <= sum) take = count(ind-1, sum-arr[ind], arr, dp);

    return dp[ind][sum] = (notTake+take) % mod;

}

int findWays(vector<int> &arr, int tar){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));

    return count(n-1, tar, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for (auto it: arr) sum += it;

    if (sum-d<0 || (sum-d)%2==1) return 0;
    return findWays(arr, (sum-d)/2);
}

// Tabulation
int findWays2(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum+1, 0));

    if (arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if (arr[0]!=0 && arr[0] <= sum) dp[0][arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        for (int tar=0; tar<=sum; tar++){
            int notTake = dp[ind-1][tar];
            int take = 0;
            if (arr[ind] <= tar) take = dp[ind-1][tar-arr[ind]];

            dp[ind][tar] = (take + notTake)%mod;
        }
    }

    return dp[n-1][sum];
}

int countPartitions2(int n, int d, vector<int> &arr) {
    int sum = 0;
    for (auto it: arr) sum += it;

    if (sum-d<0 || (sum-d)%2==1) return 0;
    return findWays2(arr, (sum-d)/2);
}

// Space Optimization
int findWays3(vector<int> &arr, int sum){
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(sum+1, 0));
    vector<int> prev(sum+1, 0);

    if (arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    
    if (arr[0]!=0 && arr[0] <= sum) prev[arr[0]] = 1;

    for (int ind=1; ind<n; ind++){
        vector<int> cur(sum+1, 0);
        for (int tar=0; tar<=sum; tar++){
            int notTake = prev[tar];
            int take = 0;
            if (arr[ind] <= tar) take = prev[tar-arr[ind]];

            cur[tar] = (take + notTake)%mod;
        }
        prev = cur;
    }

    return prev[sum];
}

int countPartitions3(int n, int d, vector<int> &arr) {
    int sum = 0;
    for (auto it: arr) sum += it;

    if (sum-d<0 || (sum-d)%2==1) return 0;
    return findWays2(arr, (sum-d)/2);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}