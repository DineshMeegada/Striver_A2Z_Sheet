#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> st;

    for (int i= 0; i<n; i++){
        int curr = asteroids[i];
        if (st.empty() || curr*st.top()>0 || (st.top()<0 && curr>0)) {
            st.push(curr);
            continue;
        }

        int flag = 1;
        while (!st.empty() && curr*st.top()<0) {
            if (abs(st.top()) < abs(curr)) st.pop();
            else {
                if (abs(st.top()) == abs(curr)) st.pop();
                flag = 0;
                break;
            }
        }

        if (flag) st.push(curr);
    }

    vector<int> res;
    while (!st.empty()) {
        res.insert(res.begin(), st.top());
        st.pop();
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
    
    vector<int> res = asteroidCollision(arr);
    for (auto it: res) cout << it << ' ';


    
    return 0;
}