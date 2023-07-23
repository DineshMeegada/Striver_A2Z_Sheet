#include <bits/stdc++.h>
using namespace std;

string reverse_words(string s){
    int n = s.size();
    string res = "", temp = "";

    int i=n-1;
    while (i>=0 && s[i]==' ') i--;
    while (i>=0) {

        while (i>=0 && s[i]!=' ') temp += s[i--];
        while (i>=0 && s[i]==' ') i--;

        reverse(temp.begin(), temp.end());
        
        res += temp ;
        if (i >= 0) res += ' ';
        temp = "";
    }
    

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    cout << "Before reversing the String :" << endl;
    cout << s << endl << endl;

    string st = reverse_words(s);

    cout << "After reversing the String :" << endl;
    cout << st;    
    
    return 0;
}