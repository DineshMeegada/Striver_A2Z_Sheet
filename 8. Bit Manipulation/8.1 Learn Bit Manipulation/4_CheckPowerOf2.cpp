#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {	
    return (n&n-1) ? false : true;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; 
    cin >> n;

    cout << isPowerOfTwo(n);

    
    return 0;
}