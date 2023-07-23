#include <bits/stdc++.h>
using namespace std;

bool isRotated(string s, string goal) {
    int n = s.size(), m = goal.size();

    for (int i=0; i<n; i++) {
        int next = (i+1)%n;
        if (goal[i]==s.back() && goal[next]==s[0]) {
            string temp = i!=n-1 ? goal.substr(next, m) + goal.substr(0, i+1) : goal;
            cout << temp << " " << i << endl;
            if (temp == s) return true;
        } 
    }

    return false;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s, goal;
    cin >> s >> goal;

    cout << isRotated(s, goal);
    
    return 0;
}