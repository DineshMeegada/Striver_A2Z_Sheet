#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i=0, j=0;
    int m = g.size(), n = s.size();
    while (i<m && j<n) {
        if(g[i]<=s[j]) i++;
        j++;
    }

    return i;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> g(n);
    for (int i=0; i<n; i++) cin >> g[i] ;
        
    vector<int> s(m);
    for (int i=0; i<m; i++) cin >> s[i] ;
    
    int content = findContentChildren(g, s);
    cout << content;    

    
    return 0;
}