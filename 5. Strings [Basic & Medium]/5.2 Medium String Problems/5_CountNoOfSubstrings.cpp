#include <bits/stdc++.h>
using namespace std;

int countOfSubstringsN2(string str, int k) {
    
}

// Time Complexity - O(N^3)
// Space Complexity - O(N)
int countOfSubstrings(string str, int max_k){
    int n = str.size(), cnt=0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            map <char, int> freq;
            for (int k=i; k<=j; k++) freq[str[k]]++;
            if (freq.size() == max_k) cnt++;
        }
    }

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string str;
    cin >> str;

    int k;
    cin >> k;

    int count = countOfSubstrings(str, k);
    cout << count;
    
    return 0;
}