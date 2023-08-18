#include <bits/stdc++.h>
using namespace std;

void helper(int ind, vector<int> arr, vector<int> temp, vector<vector<int>> &res) {
    res.push_back(temp);

    for (int i=ind; i<arr.size(); i++) {
        if (i>ind && arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
        helper(i+1, arr, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    helper(0, nums, {}, res);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<vector<int>> res = getUniqueSubsets(arr);
    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }

    
    return 0;
}