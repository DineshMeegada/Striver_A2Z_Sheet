#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k){
    int mask = 1 << k-1;
    int res = n&mask;
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    cout << isKthBitSet(n, k);
    

    
    return 0;
}