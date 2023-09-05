#include <bits/stdc++.h>
using namespace std;

vector<int> findStockSpans(vector<int>& prices) {
    int n = prices.size();
    stack<int> st;
    st.push(-1);
    vector<int> res;

    for (int i=0; i<n; i++) {
        while (st.top()!=-1 && prices[st.top()]<prices[i]) st.pop();
        res.push_back(i-st.top());
        st.push(i);
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
    
    vector<int> res = findStockSpans(arr);
    for (auto it: res) cout << it << ' ' ;
    
    
    return 0;
}