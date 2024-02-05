#include <bits/stdc++.h>
using namespace std;

// Tabulation
int findLCS(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int ind1=1; ind1<=n; ind1++){
        for (int ind2=1; ind2<=m; ind2++){
            if (s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else 
                dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }

    return dp[n][m];
}

int minInsertions(string s) {
    int n = s.size();

    string str = s;
    reverse(str.begin(), str.end());

    int len = findLCS(s, str);
    return n-len;
}

// Space Optimization
int findLCS2(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<int> prev(m+1, 0);
    for (int ind1=1; ind1<=n; ind1++){
        vector<int> cur(m+1, 0);
        for (int ind2=1; ind2<=m; ind2++){
            if (s1[ind1-1] == s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else 
                cur[ind2] = max(prev[ind2], cur[ind2-1]);
        }
        prev = cur;
    }

    return prev[m];
}

int minInsertions2(string s) {
    int n = s.size();

    string str = s;
    reverse(str.begin(), str.end());

    int len = findLCS2(s, str);
    return n-len;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}