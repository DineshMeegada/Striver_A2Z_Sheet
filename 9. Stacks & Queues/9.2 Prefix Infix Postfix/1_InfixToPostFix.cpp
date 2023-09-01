#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    return -1;
}

string infixToPostFix(string s){
    string res = "";
    stack<int> st;

    for (int i=0; i<s.size(); i++){
        char c = s[i];
        if ((c>='a' && c<='z') || (c>='0' && c<='9')) res += c;
        else if (c=='(') st.push(c);
        else if (c==')'){
            while (!st.empty() && st.top()!='(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >=  prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string exp = infixToPostFix(s);
    cout << exp;
    
    
    return 0;
}