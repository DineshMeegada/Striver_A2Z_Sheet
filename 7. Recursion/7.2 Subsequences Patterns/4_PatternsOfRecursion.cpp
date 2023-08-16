#include <bits/stdc++.h>
using namespace std;

void printSubArrWithK(int ind, vector<int> arr, int k, int curr, vector<int> temp){
    if (ind >= arr.size()) {
        if (curr == k){
            for (auto it: temp) cout << it << ' ';
            cout << endl;
        }
        return;
    }

    printSubArrWithK(ind+1, arr, k, curr, temp);

    temp.push_back(arr[ind]);
    curr += arr[ind];

    printSubArrWithK(ind+1, arr, k, curr, temp);
}

void SubArrsWithK(int ind, vector<int> arr, int k, int curr, vector<int> temp, vector<vector<int>> &res){
    if (ind >= arr.size()) {
        if (curr == k) res.push_back(temp);
        return;
    }

    printSubArrWithK(ind+1, arr, k, curr, temp);

    temp.push_back(arr[ind]);
    curr += arr[ind];

    printSubArrWithK(ind+1, arr, k, curr, temp);
}

vector<vector<int>> subArraysWithK(vector<int> arr, int k){
    vector<vector<int>> res;
    SubArrsWithK(0, arr, k, 0, {}, res);
    return res;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    
    
    return 0;
}