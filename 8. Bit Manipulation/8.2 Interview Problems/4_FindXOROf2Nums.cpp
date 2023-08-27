#include <bits/stdc++.h>
using namespace std;

int Xor(int n) {
    if (n%4 == 0) return n;
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n+1;
    if (n%4 == 3) return 0;
}

int findXOR(int L, int R){
    return Xor(R)^Xor(L-1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int l, r;
    cin >> l >> r;

    cout << findXOR(l, r);
    
    return 0;
}