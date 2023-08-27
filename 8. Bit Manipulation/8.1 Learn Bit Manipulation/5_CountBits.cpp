#include <bits/stdc++.h>
using namespace std;

int countBits(int N) {
    int cnt = 0;

    while (N!=0){
        cnt++;
        N = N&N-1;
    }

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; 
    cin >> n;

    cout << countBits(n);

    
    return 0;
}