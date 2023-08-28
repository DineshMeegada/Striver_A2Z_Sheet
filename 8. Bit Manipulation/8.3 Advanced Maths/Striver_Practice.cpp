#include <bits/stdc++.h>
using namespace std;

// Find Kth prime number
int n = 100000000;
vector<bool> sieve(100000001, true);
vector<int> ds;

void createSieve() {
    sieve[0] = false;
    sieve[1] = false;

    for (int i=2; i*i<=n; i++) {
        if (sieve[i] == true) {
            for (int j=i*i; j<=n; j+=i) {
                sieve[j] = false;
            }
        }
    }

    int limit = 86028121;
    for (int i=0; i<=limit; i++) {
        if (sieve[i] == true) ds.push_back(i);
    }

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    int k;
    cin >> k;

    createSieve();

    cout << k << "th prime number is : " << ds[k-1] ;
    


    
    return 0;
}