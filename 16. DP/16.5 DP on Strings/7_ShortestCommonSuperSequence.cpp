#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int ind1=1; ind1<=n; ind1++){
        for (int ind2=1; ind2<=m; ind2++){
            if (str1[ind1-1]==str2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }

    int i=n, j=m;
    string ans = "";
    while (i>0 && j>0){
        if (str1[i-1] == str2[j-1]){
            ans += str1[i-1];
            i--;
            j--;
        }else if (dp[i-1][j] >= dp[i][j-1]){
            ans += str1[i-1];
            i--;
        }else {
            ans += str2[j-1];
            j--;
        }
    }

    while (i>0) ans += str1[--i];
    while (j>0) ans += str2[--j];

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}