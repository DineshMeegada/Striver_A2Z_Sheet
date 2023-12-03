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


string printMinNumberForPattern(string s){
    int n = s.size();
    
    string ans = "";
    for (int i=1; i<=n+1; i++) {
        ans += to_string(i);
    }
    
    int i = 0;
    while (i<n) {
        int start = i;
        while (i<n && s[i]=='D') i++;
        
        int end = i;
        while (start <= end) {
            swap(ans[start++], ans[end--]);
        }
        
        cout << start << ' ' << end << endl;
    }
    
    return ans;
}



int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    string res = printMinNumberForPattern(s);
    cout << res;

    
    
    return 0;
}