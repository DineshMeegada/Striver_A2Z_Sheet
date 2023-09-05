#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int left = 0, right = 0;
    int max_len = 0;
    unordered_set<char> letters;

    while (right < n) {
        while (letters.find(s[right])!=letters.end()){
            letters.erase(s[left++]);
        }
        
        letters.insert(s[right]);
        max_len = max(max_len, right-left+1);
        right++;
    } 

    return max_len;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int len = lengthOfLongestSubstring(s);
    cout << len;

    
    return 0;
}