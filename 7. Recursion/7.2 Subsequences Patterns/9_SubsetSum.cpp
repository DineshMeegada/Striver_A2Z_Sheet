#include <bits/stdc++.h>
using namespace std;

void subsVec(int ind, int curr, vector<int> arr, vector<int> &res){
    if (ind>=arr.size()){
        res.push_back(curr);
        return;
    }

    curr += arr[ind];
    subsVec(ind+1, curr, arr, res);
    
    curr -= arr[ind];
    subsVec(ind+1, curr, arr, res);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> res;
    subsVec(0, 0, num, res);

    sort(res.begin(), res.end());
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> ans = subsetSum(arr);
    for (auto it: ans) cout << it << ' ';    


    
    return 0;
}