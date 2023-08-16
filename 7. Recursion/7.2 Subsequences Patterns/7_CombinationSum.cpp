#include <bits/stdc++.h>
using namespace std;

void distCombs(int ind, vector<int> temp, vector<int> arr, int k, vector<vector<int>> &res) {
    if (k<0) return;
    if (ind >= arr.size()) {
        if (k==0) res.push_back(temp);

        return ;
    }

    temp.push_back(arr[ind]);
    distCombs(ind, temp, arr, k-arr[ind], res);

    temp.pop_back();
    distCombs(ind+1, temp, arr, k,res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    distCombs(0, {}, candidates, target, res);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<vector<int>> res = combinationSum(arr, k);
    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }

    
    return 0;
}