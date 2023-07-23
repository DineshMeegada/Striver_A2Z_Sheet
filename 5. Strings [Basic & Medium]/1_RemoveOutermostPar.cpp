#include <bits/stdc++.h>
using namespace std;

string removedString(string s){
    int opened = 0;
    string res = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') opened++;
        else opened--;

        if (opened>1 || (opened==1 && s[i]==')')) res += s[i];
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    string st = removedString(s);
    cout << st;
    
    return 0;
}