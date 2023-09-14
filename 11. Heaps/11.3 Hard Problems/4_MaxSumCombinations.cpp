#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr1, vector<int> &arr2, int k) {
    sort(arr1.begin(), arr1.end(), greater<int> ());
    sort(arr2.begin(), arr2.end(), greater<int> ());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    int n = arr1.size();
    vector<int> ans;

    // for (auto it: arr1) cout << it << ' ';
    // cout << endl;
    // for (auto it: arr2) cout << it << ' ';
    // cout << endl;

    pq.push({arr1[0]+arr2[0], {0,0}});
    while (k--){
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();
        ans.push_back(curr.first);

        if (curr.second.first+1 < n && st.find({curr.second.first+1, curr.second.second})==st.end()) {
            pq.push({arr1[curr.second.first+1]+arr2[curr.second.second], {curr.second.first+1, curr.second.second}});
            st.insert({curr.second.first+1, curr.second.second});
        }

        if (curr.second.second+1 < n && st.find({curr.second.first, curr.second.second+1})==st.end()) {
            pq.push({arr1[curr.second.first]+arr2[curr.second.second+1], {curr.second.first, curr.second.second+1}});
            st.insert({curr.second.first, curr.second.second+1});
        }
    }

    return ans;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr1(n);
    for (int i=0; i<n; i++) cin >> arr1[i] ;
    
    vector<int> arr2(n);
    for (int i=0; i<n; i++) cin >> arr2[i] ;
    
    vector<int> res = solve(arr1, arr2, k);
    for (auto it: res) cout << it << ' ';
    
    return 0;
}