#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n){
    vector<int> res(n) ;
    stack<int> st;

    for (int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while (!st.empty() && st.top() <= curr) st.pop();
        
        if (!st.empty()) res[i] = st.top();
        else res[i] = -1;

        st.push(curr);
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
    
    vector<int> res = nextGreaterElement(arr, n);
    for (auto it: res) cout << it << ' ' ;
    


    
    return 0;
}