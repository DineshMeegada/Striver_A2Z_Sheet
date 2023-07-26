#include <bits/stdc++.h>
using namespace std;

int sumOfBeauty(string s){
    int n = s.size();
    int beauty = 0;
    for (int i=0; i<n; i++){
        unordered_map<char, int> freq;
        for (int j=i; j<n; j++) {
            freq[s[j]]++;
            int min_count = INT_MAX, max_count = INT_MIN;
            for (auto it: freq) {
                min_count = min(min_count, it.second);
                max_count = max(max_count, it.second);
            }

            beauty += max_count - min_count;
        }
    }

    return beauty;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int beauty = sumOfBeauty(s);
    cout << beauty;
    
    return 0;
}