#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long power (long long x, long long n) {
    if (n==0) return 1;
    
    if (n%2 == 0) return power(x*x % mod, n/2);
    return x*power(x*x % mod, (n-1)/2) % mod;
}

int countGoodNumbers(long long n) {
    long long evens = n/2 + n%2;
    long long odds = n/2;

    return (power(5, evens) * power(4, odds)) % mod;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;

    cout << countGoodNumbers(n);
    
    return 0;
}