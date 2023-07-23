#include <bits/stdc++.h>
using namespace std;

string largest_odd(string s){

    for (int i=s.size() - 1; i>=0; i--){
        if (int(s[i])%2 == 1) return s.substr(0, i+1);
    }

    return "";
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    cout << largest_odd(s);
    
    return 0;
}