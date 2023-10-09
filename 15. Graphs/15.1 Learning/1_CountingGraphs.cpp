#include <bits/stdc++.h>
using namespace std;

int countingGraphs(int n) {
    int edges = n*(n-1)/2;
    return 1<<edges;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;    
    cin >> n;
    
    cout << countingGraphs(n);
    
    return 0;
}