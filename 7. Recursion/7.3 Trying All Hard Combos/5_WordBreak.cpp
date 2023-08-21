#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, string s, vector<string> &words) {
    if (ind >= s.size()) return true;

    for (auto it: words){
        if (s[ind] == it[0]){
            int k = 0, i=ind;
            while (k<it.size() && s[i]==it[k]){
                k++;
                i++;
            }

            if (k!=it.size()) continue;
            if (solve(i, s, words)) return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    return solve(0, s, wordDict);
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