#include <bits/stdc++.h>
using namespace std;

// Max number of nodes present on Nth level of tree
int numberOfNodes(int N){
    return pow(2,N-1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    cout << numberOfNodes(n);
    
    return 0;
}