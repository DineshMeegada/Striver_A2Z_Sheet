#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int N){
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    vector<int> res;
    int sum = 0, i=coins.size()-1;
    
    while (sum<N && i>=0) {
        if (sum+coins[i] <= N) {
            res.push_back(coins[i]);
            sum += coins[i];
        } else i--;
    }
    
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n ;

    vector<int> ans = MinimumCoins(n);
    for (auto it: ans) cout << it << ' ' ;    
    
    return 0;
}