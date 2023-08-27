#include <bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int> res;
    for (int i=1; i*i<=n; i++) {
        if (n%i == 0){
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n; 

    vector<int> divs = printDivisors(n);
    for (auto it: divs) cout << it << ' ';

    
    return 0;
}