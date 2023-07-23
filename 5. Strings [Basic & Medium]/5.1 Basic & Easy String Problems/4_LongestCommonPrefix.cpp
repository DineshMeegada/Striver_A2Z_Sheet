#include <bits/stdc++.h>
using namespace std;

string common_string(vector<string> strs){
    string common = strs[0];
    for (int i=1; i<strs.size(); i++) {
        int j;
        string word = strs[i];
        for (j=0; j<strs[i].size(); j++){
            if (common[j]!=word[j]) break;
        }

        common = word.substr(0, j);
    }
    return common;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i=0; i<n; i++) cin >> strs[i];

    // cout << strs[0];

    string str = common_string(strs);
    cout << str;

    return 0;
}