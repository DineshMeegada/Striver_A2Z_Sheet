#include <bits/stdc++.h>
using namespace std;

string sortCharsByFreq(string s) {
    int n = s.size();

    unordered_map<char, int> freqs;
    for (int i=0; i<n; i++) freqs[s[i]]++;

    priority_queue<pair<int, char>> counts;
    for (auto it: freqs) counts.push({it.second, it.first});

    string res = "";
    while (!counts.empty()) {
        auto item = counts.top();
        res.append(item.first, item.second);
        counts.pop();
    }
    

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    cout << s << endl;
    string sorted_s = sortCharsByFreq(s);
    cout << sorted_s;
    
    return 0;
}