#include <bits/stdc++.h>
using namespace std;

vector<int> countPrimes(int n)
{
    vector<int> res;
    for (int i=2; i*i<=n; i++){
        if (n%i == 0) {
            res.push_back(i);
            while(n%i == 0) n/=i;
        }
    }
    if (n>1) res.push_back(n);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> primeFacts = countPrimes(n);
    for (auto it: primeFacts) cout << it << ' ';

    
    return 0;
}