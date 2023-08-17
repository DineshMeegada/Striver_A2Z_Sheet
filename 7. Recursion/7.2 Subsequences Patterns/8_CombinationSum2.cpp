#include <bits/stdc++.h>
using namespace std;

void distCombsDFS(int ind, vector<int> arr, int k, vector<int> temp, vector<vector<int>> &res) {
    if (k<0) return;
    if (ind >= arr.size()) {
        if (k==0) res.push_back(temp);
        return;
    }

    temp.push_back(arr[ind]);
    distCombsDFS(ind+1, arr, k-arr[ind], temp, res);

    temp.pop_back();
    while (ind+1<arr.size() && arr[ind]==arr[ind+1]) ind++;

    distCombsDFS(ind+1, arr, k, temp, res);
}

void distCombsBFS(int ind, vector<int> arr, int k, vector<int> temp, vector<vector<int>> &res){
    if (k==0) {
        res.push_back(temp);
        return;
    }

    for (int i=ind; i<arr.size(); i++){
        if (i>ind && arr[i]==arr[i-1]) continue;
        if (arr[i]>k) break;

        temp.push_back(arr[i]);
        distCombsBFS(i+1, arr, k-arr[i], temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    distCombsBFS(0, candidates, target, {}, res);

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<vector<int>> res = combinationSum2(arr, k);
    for (auto combs: res){
        for (auto it: combs) cout << it << ' ';
        cout << endl;
    }

    
    return 0;
}