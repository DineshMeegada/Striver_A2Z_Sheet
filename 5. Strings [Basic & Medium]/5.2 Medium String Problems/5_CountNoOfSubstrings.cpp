#include <bits/stdc++.h>
using namespace std;

int countUptoK(string str, int k) {
    unordered_map<char, int> cnt;
    int left = 0, res = 0;
    for (int i=0; i<str.size(); i++) {
        cnt[str[i]]++;
        while (cnt.size() > k) {
            cnt[str[left]]--;
            if (cnt[str[left++]] == 0) cnt.erase(str[left]);
        }

        res += i-left+1;
    }

    return res;
}

int countOfSubstringsN(string str, int k) {
    return (countUptoK(str, k) - countUptoK(str, k-1));
}

int countOfSubstringsN2(string str, int k) {
    int res = 0, n = str.size();
    for (int i=0; i<n; i++) {
        unordered_map<char, int> cnt;
        for (int j=i; j<n; j++) {
            cnt[str[j]]++;
            if (cnt.size() == k) res++;
            if (cnt.size()>k) break;
        }
    }

    return res;
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

    int count = countOfSubstringsN2(str, k);
    cout << count;
    
    return 0;
}