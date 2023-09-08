#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
	int n = s.size(), m = t.size();
    int k = 0, resLen = INT_MAX;
    pair<int, int> res = {-1, -1};

    for (int r=0; r<n; r++) {
        if (s[r]==t[k]) k++;
        if (k==m) {
            int l = r;
            k--;
            while (l>=0 && k>=0){
                if (s[l] == t[k]) k--;
                l--;
            }
            l++;
            if (resLen>(r-l+1)) {
                resLen = r-l+1;
                res = {l, r};
            }
            k = 0;
            r = l+1;
        }

    }

    cout << endl;
    if (res.first == -1) return "";
    return s.substr(res.first, res.second-res.first+1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >>t;

    for (int i=0; i<t; i++) {
        string s, t;
        cin >> s >> t;

        string ans = minWindow(s, t);
        cout << ans << endl << endl;
    }
    
    return 0;
}