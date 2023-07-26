#include <bits/stdc++.h>
using namespace std;

int palindromeLen (string s, int left, int right){
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right]){
        left--;
        right++;
    }

    return right - left - 1;
}

string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, end = 0;

    for (int i=0; i<n; i++) {
        int len1 = palindromeLen(s, i, i);
        int len2 = palindromeLen(s, i, i+1);
        int len = max(len1, len2);
        
        if (end - start < len){
            end = i + (len/2);
            start = i - (len - 1)/2;
        }
    }

    return s.substr(start, end + 1 - start);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    string subString = longestPalindrome(s);
    cout << subString;

    return 0;
}