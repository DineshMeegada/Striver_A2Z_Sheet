#include <bits/stdc++.h>
using namespace std;

// Backtracking Partially accepted

// bool solve(int ind, string s, vector<string> &words) {
//     if (ind >= n) return true;

//     for (auto it: words){
//         if (s[ind] == it[0]){
//             int k = 0, i=ind;
//             while (k<it.size() && s[i]==it[k]){
//                 k++;
//                 i++;
//             }

//             if (k!=it.size()) continue;
//             if (solve(i, s, words)) return true;
//         }
//     }

//     return false;
// }

// bool wordBreak(string s, vector<string>& wordDict) {
//     return solve(0, s, wordDict);
// }


// DP Approach (Optimized)

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();

    vector<bool> dp (n+1, false);
    dp[n] = true;

    for (int i=n-1; i>=0; i--) {
        for (auto w: wordDict){
            int w_len = w.size();
            if (i+w_len<=n && s.substr(i, w_len)==w){
                dp[i] = dp[i + w_len];
            }

            if (dp[i]) break;
        }
    }

    return dp[0];
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    vector<string> words = {"cats","dog","sand","and","cat"};

    cout << wordBreak(s, words);
    
    return 0;
}