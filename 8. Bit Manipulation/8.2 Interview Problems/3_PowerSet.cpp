#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> res;
    for (int i=0; i<pow(2,n); i++){
        vector<int> temp;
        for (int j=0; j<n; j++){
            if(i&(1<<j)) temp.push_back(nums[j]);
        }
        res.push_back(temp);
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    
    vector<vector<int>> res = subsets(arr);
    for (auto subs: res) {
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }
    
    return 0;
}