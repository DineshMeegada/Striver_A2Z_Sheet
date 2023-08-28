#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> sieve(n+1, true);
    sieve[0] = false;
    sieve[1] = false;

    for (int i=2; i*i<=n; i++){
        if (sieve[i]) {
            for (int j=i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        } 
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (sieve[i]) {
            cnt++;
        }
    }

    return cnt;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    cout << "Total number of primes : " << countPrimes(n);


    
    return 0;
}