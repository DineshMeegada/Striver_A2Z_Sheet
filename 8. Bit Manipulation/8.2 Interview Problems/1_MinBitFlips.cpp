#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int cnt = 0;
    while (start>0 || goal>0) {
        int temp1 = start&1, temp2 = goal&1;
        if (temp1 != temp2) cnt++;
        start >>= 1;
        goal >>= 1;
    }

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int start, goal;
    cin >> start >> goal;

    cout << minBitFlips(start, goal);
    
    
    return 0;
}