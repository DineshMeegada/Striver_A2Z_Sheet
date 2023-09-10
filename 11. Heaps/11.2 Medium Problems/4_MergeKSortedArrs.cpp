#include <bits/stdc++.h> 
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it: kArrays) {
        for (auto num: it) pq.push(num);
    }

    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for (int j=0; j<n; j++) {
        for (int i=0; i<m; i++) cin >> arr[j][i] ;
    }

    vector<int> res = mergeKSortedArrays(arr, n);
    for (auto it: res) cout << it << ' ';
    
    
}