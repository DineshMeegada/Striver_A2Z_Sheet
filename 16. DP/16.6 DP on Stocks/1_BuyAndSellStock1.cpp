#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int prev = prices[0];
    int ans = 0;

    for (int i=1; i<n; i++){
        ans = max(ans, prices[i]-prev);
        prev = min(prev, prices[i]);
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}