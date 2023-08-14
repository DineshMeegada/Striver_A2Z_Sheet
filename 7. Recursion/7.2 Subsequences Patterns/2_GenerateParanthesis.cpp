#include <bits/stdc++.h>
using namespace std;

void paranthesis(int open, int close, string st, vector<string> &pars) {
    if (open==0 && close==0) {
        pars.push_back(st);
        return;
    }

    if(open>0) {
        string st2 = st;
        st2.push_back('(');
        paranthesis(open-1, close, st2, pars);
    }

    if (open<close) {
        string st3 = st;
        st3.push_back(')');
        paranthesis(open, close-1, st3, pars);
    }
}

vector<string> generateParanthesis(int n) {
    vector<string> pars;
    paranthesis(n, n, "", pars);
    return pars;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<string> pars = generateParanthesis(n);
    for (auto it: pars) cout << it << ' ';
    
    return 0;
}