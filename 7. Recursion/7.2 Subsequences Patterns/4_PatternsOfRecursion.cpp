#include <bits/stdc++.h>
using namespace std;

// Printing all subsequences with sum k
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


// returning subarrays with sum k
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


// print any one subarray with sum k
bool printOneSubArr(int ind, vector<int> arr, int k, int curr, vector<int> temp){
    if (ind >= arr.size()){
        if (curr == k) {
            for (auto it: temp) cout << it << ' ';
            cout << endl;
            return true;
        }
        return false;
    }

    if (printOneSubArr(ind+1, arr, k, curr, temp)) return true;

    temp.push_back(arr[ind]);
    curr += arr[ind];

    if (printOneSubArr(ind+1, arr, k, curr, temp)) return true;

    return false; 
}


// Count the number of subarrays of sum K
int countSubs(int ind, vector<int> arr, int k, int curr){
    if (ind >= arr.size()){
        if (curr == k) return 1;
        return 0;
    }

    int a = countSubs(ind+1, arr, k, curr);

    curr += arr[ind];
    int b = countSubs(ind+1, arr, k, curr);

    return a+b;
}

// Count the number of unique subsequences
void distSubs(int ind, string s, string temp, int &cnt){
    if (ind >= s.size()){
        for (auto it: temp) cout << it << ' ';
        cout << endl;
        cnt++;
        return;
    }

    temp.push_back(s[ind]);
    distSubs(ind+1, s, temp, cnt);

    temp.pop_back();
    while (ind<s.size() && s[ind]==s[ind+1]) ind++;
    distSubs(ind+1, s, temp, cnt);
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // int n, k;
    // cin >> n >> k;
    
    // vector<int> arr(n);
    // for (int i=0; i<n; i++) cin >> arr[i] ;
    
    // bool sub = printOneSubArr(0, arr, k, 0, {});
    
    // int count = countSubs(0, arr, k, {});
    // cout << count ;
    

    string s;
    cin >> s;
    int cnt1 = 0;

    distSubs(0, s, "", cnt1);
    cout << cnt1 << endl;;


    return 0;
}