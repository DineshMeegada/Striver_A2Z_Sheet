#include <bits/stdc++.h>
using namespace std;

// Recursion
int fib1(int n){
    if (n <= 1) return n;
    return fib1(n-1) + fib1(n-2);
}

// Memorization
int fib2(int n, vector<int> &dp){
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = fib2(n-1, dp) + fib2(n-2, dp);
}

// Tabulation
int fib3(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Space Optimization
int fib4(int n){
    if (n <= 1) return 1;
    int prev = 1, prev2 = 0;

    for (int i=2; i<=n; i++){
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    int fib_num = fib4(n);
    cout << fib_num;
    
    
    return 0;
}