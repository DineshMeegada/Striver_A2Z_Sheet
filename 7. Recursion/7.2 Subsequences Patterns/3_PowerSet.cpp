#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> PowerSet(vector<int> arr) {
    vector<vector<int>> res = {{}};

    for (auto i: arr) {
        vector<vector<int>> subset;
        for (auto it: res){
            vector<int> it1 = it;
            it1.push_back(i);
            subset.push_back(it1);
        }
        for (auto lst: subset) res.push_back(lst);
    }

    return res;
}

void printPowerSet(int i, vector<int> arr, vector<int> temp, vector<vector<int>> &res){
    if (i>=arr.size()) {
        res.push_back(temp);
        return;
    }

    printPowerSet(i+1, arr, temp, res);

    temp.push_back(arr[i]);
    printPowerSet(i+1, arr, temp, res);

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    // vector<vector<int>> powerSet = PowerSet(arr);
    // for (auto subs: powerSet){
    //     for (auto it : subs) cout << it << ' ' ;
    //     cout << endl;
    // }

    vector<vector<int>> res;
    printPowerSet(0, arr, {}, res);

    for (auto subs: res){
        for (auto it: subs) cout << it << ' ';
        cout << endl;
    }    


    return 0;
}

