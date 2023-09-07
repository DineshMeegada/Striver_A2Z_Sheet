#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &s){
    int n = s.size();
    int left = 0;
    unordered_map<char, int> freq;
    int ans = 0;

    for (int right=0; right<n; right++) {
        freq[s[right]]++;
        while (freq.size() > k){
            freq[s[left]]--;
            if (freq[s[left]]==0) freq.erase(s[left]);
            left++;
        }

        ans = max(ans, right-left+1);
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int k;
    cin >> k;

    int len = kDistinctChars(k, s);
    cout << len;
    
    return 0;
}