#include <bits/stdc++.h>
using namespace std;

bool isAnagramSorting(string s, string t) {
    sort (s.begin(), s.end());
    sort (t.begin(), t.end());
    return s==t;
}

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> count;

    for (int i=0; i<s.size(); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    for (auto it: count){
        if (it.second) return false;
    }

    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t);
    
    return 0;
}