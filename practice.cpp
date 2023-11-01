#include <bits/stdc++.h>
using namespace std;

string betterCompression(string s){
    map<char, int> freq;

    int n = s.size(), i = 0;
    while (i < n) {
        char letter = s[i++];

        string temp = "";
        while (i<n && s[i]-'0'>=0 && s[i]-'0'<=9){
            temp = temp + s[i];
            i++;
        }

        int f = stoi(temp);

        freq[letter] += f;        
    }

    string res = "";
    for(auto it: freq) {
        res += it.first;
        res += to_string(it.second);
    }

    return res;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    string res = betterCompression(s);
    cout << res;

    
    
    return 0;
}