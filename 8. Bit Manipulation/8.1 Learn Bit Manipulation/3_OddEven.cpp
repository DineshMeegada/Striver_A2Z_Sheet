#include <bits/stdc++.h>
using namespace std;

string oddEven(int N){
    return N&1 ? "odd" : "even";
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; 
    cin >> n;

    cout << oddEven(n);

    
    return 0;
}