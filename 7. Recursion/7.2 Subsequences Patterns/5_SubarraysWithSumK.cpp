#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subArraysWithK(vector<int> arr, int k) {
    int start = 0, sum = 0;
    int n = arr.size();
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        sum += arr[i];

        while (sum>k && start<n) {
            sum -= arr[start++];
        }

        if (sum == k) {
            vector<int> temp;
            for (int j=start; j<=i; j++) temp.push_back(arr[j]);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<vector<int>> res = subArraysWithK(arr, k);
    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }
    
    
    return 0;
}