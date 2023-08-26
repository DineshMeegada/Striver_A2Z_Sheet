#include <bits/stdc++.h>
using namespace std;

int setBits(int N){
    return (N|(N+1));
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; 
    cin >> n;

    cout << setBits(n);

    
    return 0;
}