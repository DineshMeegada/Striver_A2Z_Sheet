#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    int l = 0, len = INT_MAX;
    int have = 0, need = t.size();
    unordered_map<char, int> s_map, t_map;
    pair<int, int> res = {-1, -1};

    for (auto it: t) t_map[it]++;

    for (int r=0; r<n; r++) {
        char curr = s[r];

        if (t_map.find(curr) != t_map.end()) {
            s_map[curr]++;
            if (s_map[curr] <= t_map[curr]) have++;

            while (have == need) {
                if (len > (r-l+1)){
                    len = r-l+1;
                    res = {l, r};
                }
                if (s_map.find(s[l])!=s_map.end()) {
                    if (s_map[s[l]] <= t_map[s[l]]) have--;
                    s_map[s[l]]--;
                }
                l++;
            }
        }
    }

    if (res.first==-1) return "";
    return s.substr(res.first, res.second-res.first+1);

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    string ans = minWindow(s, t);
    cout << ans;

    
    return 0;
}