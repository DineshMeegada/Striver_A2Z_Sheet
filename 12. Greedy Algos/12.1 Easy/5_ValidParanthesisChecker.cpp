#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int leftMin = 0, leftMax = 0;

    for (auto it: s) {
        if (it == '(') {
            leftMin++;
            leftMax++;
        } else if (it == ')') {
            leftMin--;
            leftMax--;
        } else {
            leftMin--;
            leftMax++;
        }

        if (leftMax < 0) break;
        leftMin = max(0, leftMin);
    }

    return leftMin==0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    cout << checkValidString(s);

    
    return 0;
}