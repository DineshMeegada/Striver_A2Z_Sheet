#include <bits/stdc++.h>
using namespace std;

int findMaxDepthOfPar(string s){
    int cnt = 0, res = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') res = max(res, ++cnt);
        else if (s[i] == ')') cnt--;
    }

    return res;
}

int findMaxDepth(string s){
    stack<char> my;
    int max=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
        my.push('(');
        else if(s[i]==')'){
            if(max<my.size())
            max=my.size();
            my.pop();
        }
        else
        continue;
    }
    return max;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int max_depth = findMaxDepthOfPar(s);
    cout << max_depth;
    
    return 0;
}