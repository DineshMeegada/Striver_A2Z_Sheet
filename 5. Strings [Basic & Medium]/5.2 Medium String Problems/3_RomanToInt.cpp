#include <bits/stdc++.h>
using namespace std;

int romanToInt(string roman){
    unordered_map <char, int> symbols = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int n = roman.size();
    int num = 0;

    for (int i=0; i<n; i++) {
        if (i<n-1 && symbols[roman[i+1]]>symbols[roman[i]]) num -= symbols[roman[i]];
        else num += symbols[roman[i]];
    }
    return num;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string roman;
    cin >> roman;

    int integer = romanToInt(roman);
    cout << integer;
    
    return 0;
}