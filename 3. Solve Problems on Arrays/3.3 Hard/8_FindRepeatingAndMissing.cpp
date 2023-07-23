#include <bits/stdc++.h>
using namespace std;

vector<int> BruteFindRepeatingAndMissing(vector<int> arr, int n) {
    int freq[n] = {0};
    
    for (int it: arr) freq[it - 1] += 1;

    int repeating = -1, missing = -1;
    for (int i=0; i<n; i++) {
        if (freq[i] == 2) repeating = i+1;
        else if (freq[i] == 0) missing = i+1;
    }

    return {repeating, missing};
}

vector<int> findRepeatingAndMissing (vector<int> arr, int n) {
    long long sN = n * (n+1) / 2;
    long long sN2 = n * (n+1) * (2*n+1) / 6;

    long long s = 0, s2 = 0;
    for (int it: arr) {
        s += it;
        s2 += it*it;
    } 

    long long val1 = sN - s;
    long long val2 = sN2 - s2;

    val2 = val2/val1;

    long long mis = (val1 + val2) / 2;
    long long rep = val2 - mis;

    return {(int)rep, (int)mis};
}

int main() {

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) cin >> arr[i] ;

    vector<int> res = findRepeatingAndMissing(arr, n);

    for (int it: res) cout << it << " " ;


    return 0;
}