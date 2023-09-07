#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    int freq[3] = {0, 0, 0};
    int ans = 0, left = 0;

    for (int right=0; right<n; right++) {
        freq[s[right]-'a']++;

        while (freq[0] && freq[1] && freq[2]){
            freq[s[left++]-'a']--;
        }

        ans += left;
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int count = numberOfSubstrings(s);
    cout << count;

    
    return 0;
}