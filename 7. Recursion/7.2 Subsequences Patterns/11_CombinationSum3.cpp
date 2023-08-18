#include <bits/stdc++.h>
using namespace std;

void helper (int cnt, vector<int> temp, int k, int n, int sum, vector<vector<int>> &res) {

    if (sum>n || cnt>k) return ;
    if (cnt==k && sum == n) {
        res.push_back(temp);
        return;
    }

    for (int i=temp.size() ? temp.back()+1 : 1; i<=9; i++) {
        temp.push_back(i);
        if (sum+i > n) break;
        helper(cnt+1, temp, k, n, sum+i, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    vector<vector<int>> res;
    helper(0, {}, k, n, 0, res);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int k, n;
    cin >> k >> n;

    vector<vector<int>> res = combinationSum(k, n);
    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }

    
    return 0;
}