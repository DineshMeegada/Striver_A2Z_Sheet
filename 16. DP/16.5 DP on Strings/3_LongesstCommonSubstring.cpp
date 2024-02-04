#include <bits/stdc++.h>
using namespace std;

// Tabulation
int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;
    for (int ind1=1; ind1<=n; ind1++){
        for (int ind2=1; ind2<=m; ind2++){
            if (str1[ind1-1] == str2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans = max(ans, dp[ind1][ind2]);
            } else dp[ind1][ind2] = 0;
        }
    }

    return ans;
}

// Space Optimization
int lcs2(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> prev(m+1, 0);

    int ans = 0;
    for (int ind1=1; ind1<=n; ind1++){
        vector<int> cur(m+1, 0);
        for (int ind2=1; ind2<=m; ind2++){
            if (str1[ind1-1] == str2[ind2-1]){
                cur[ind2] = 1 + prev[ind2-1];
                ans = max(ans, cur[ind2]);
            } else cur[ind2] = 0;
        }

        prev = cur;
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}