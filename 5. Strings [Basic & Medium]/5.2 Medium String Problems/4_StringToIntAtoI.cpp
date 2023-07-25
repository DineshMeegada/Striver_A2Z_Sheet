#include <bits/stdc++.h>
using namespace std;

int stringToInteger(string s){
    int n = s.size(), sign = 1;
    int res = 0, i=0;
    int max_num = INT_MAX, min_num = INT_MIN;

    while (i<n && s[i]==' ') i++;
    if (s[i++]=='-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') i++;

    while (i<n && s[i]-'0'>=0 && s[i]-'0'<=9) {
        if (res > max_num/10 || res==max_num/10 && s[i]-'0' > max_num%10) {
            return sign==1 ? max_num : min_num;
        }
        res = res*10 + (s[i++]-'0');
    }
    
    return res*sign;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int num = stringToInteger(s);
    cout << num;
    
    return 0;
}