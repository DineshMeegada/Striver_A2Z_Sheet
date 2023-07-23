#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map <char, char> map_s, map_t ;

    for (int i=0; i<s.size(); i++) {
        cout << s[i] << "->" << map_s[s[i]] << "    " << t[i] << "->" << map_t[t[i]] << endl;
        if (map_s[s[i]] && map_s[s[i]]!=t[i]) return false;
        if (map_t[t[i]] && map_t[t[i]]!=s[i]) return false;

        map_s[s[i]] = t[i];
        map_t[t[i]] = s[i];
    }

    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    bool iso = isIsomorphic(s, t);
    cout << iso ;
    
    
    return 0;
}