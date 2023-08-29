#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<int> st;
    unordered_map<char, char> dict = {{')', '('}, {']', '['}, {'}', '{'}};

    for (auto par: s) {
        if (par=='(' || par=='{' || par=='[') st.push(par);
        else {
            if (st.empty() || dict[par]!=st.top()) return false;
            st.pop();
        }
    }

    return st.empty();
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    cout << isValid(s);

    
    return 0;
}