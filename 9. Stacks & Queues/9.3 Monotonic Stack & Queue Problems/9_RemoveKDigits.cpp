#include <bits/stdc++.h>
using namespace std;

string removeKdigitsFirst(string s, int k) {
    int n = s.size();
    stack<char> st;

    for (int i=0; i<n; i++) {
        while (!st.empty() && st.top()>s[i] && k-->0) st.pop();

        st.push(s[i]);
    }

    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    int ind = 0;
    while (res[ind]=='0') ind++;

    return res.substr(ind);
}

string removeKdigits(string &s, int k) {
    int n = s.size();
    string res = "";

    for (int i=0; i<n; i++) {
        while (res.size() && res.back()>s[i] && k-->0) res.pop_back();
        if (res.size() || s[i]!='0') res.push_back(s[i]);
    }

    cout << res << "    " << k ;
    while (res.size() && k-->0) res.pop_back();

    return (res=="") ? "0" : res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s ;

    int k; 
    cin >> k;

    string res =  removeKdigits(s, k) ;
    cout << res;


    
    return 0;
}