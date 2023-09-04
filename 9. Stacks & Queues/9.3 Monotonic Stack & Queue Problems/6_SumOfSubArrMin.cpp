#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int MOD = 1000000007;
    int n = arr.size();
    stack<int> st;
    st.push(-1);

    long res = 0;
    for (int i=0; i<=n; i++) {

        while (st.top()!=-1 && (i==n || arr[st.top()]>=arr[i])) {
            int mid = st.top();
            st.pop();

            long contribution = (mid-st.top())*(i-mid)%MOD;
            res += arr[mid]*contribution;
            res %= MOD;
        }

        st.push(i);
    }

    return (int) res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int ans = sumSubarrayMins(arr);
    cout << ans;    


    
    return 0;
}