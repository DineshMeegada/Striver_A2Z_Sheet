#include <bits/stdc++.h>
using namespace std;

int maxCount (unordered_map<char, int> freq) {
    int maxFreq = 0;
    for (auto it: freq) {
        maxFreq = max(maxFreq, it.second);
    }
    return maxFreq;
}

int characterReplacementBetter(string s, int k) {
    int n = s.size();
    int maxFreq = 0;
    unordered_map<char, int> freq;

    int left = 0, right = 0;
    int res = 0;
    while (right < n){
        freq[s[right]]++;
        
        while (right-left+1-maxCount(freq) > k) {
            freq[s[left++]]--;
        }

        res = max(res, right-left+1);
        right++;
    }

    return res;
}

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxFreq = 0;
    unordered_map<char, int> freq;

    int left = 0;
    int res = 0;
    for (int right=0; right<n; right++){
        freq[s[right]]++;
        maxFreq = max(maxFreq, freq[s[right]]);
        
        while (right-left+1-maxFreq > k) {
            freq[s[left++]]--;
        }

        res = max(res, right-left+1);
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s; 

    int k;
    cin >> k;

    int len = characterReplacement(s, k);
    cout << len;

    
    return 0;
}