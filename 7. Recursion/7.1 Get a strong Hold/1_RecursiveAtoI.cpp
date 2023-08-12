#include <bits/stdc++.h>
using namespace std;

int myAtoI(string s, int i, int sign, int res){
    int max_int = INT_MAX;

    if (i==s.size() || s[i]-'0'<0 || s[i]-'0'>9) return sign*res;
    if (res>max_int/10 || (res==max_int/10 && s[i]-'0'>max_int%10)) {
        return sign==1 ? INT_MAX : INT_MIN;
    }

    res = res*10 + (s[i]-'0');
    return (myAtoI(s, i+1, sign, res));
}

int createAtoi(string s) {
    // Write your code here.
    int i=0, sign=1;
    while(s[i]==' ') i++;
    if (s[i]=='-'){
        sign = -1;
        i++;
    } else if (s[i]=='+') i++;

    return myAtoI(s, i, sign, 0);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    cout << createAtoi(s);
    
    return 0;
}