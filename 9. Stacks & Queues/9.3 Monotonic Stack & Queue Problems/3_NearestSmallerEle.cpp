#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;

    for (int i=0; i<n; i++) {
        int curr = arr[i];
        while (!st.empty() && st.top()>=curr) st.pop();

        if (!st.empty()) arr[i] = st.top();
        else arr[i] = -1;

        st.push(curr);
    }

    return arr;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> res = prevSmaller(arr);
    for (auto it: res) cout << it << ' ' ;

    
    return 0;
}