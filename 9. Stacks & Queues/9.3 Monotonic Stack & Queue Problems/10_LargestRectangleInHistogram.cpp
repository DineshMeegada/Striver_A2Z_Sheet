#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    st.push(-1);

    int rect = 0;
    for (int i=0; i<=n; i++){
        while (st.top()!=-1 && (i==n || heights[st.top()]>heights[i])){
            int ind = st.top();
            st.pop();

            int width = i-st.top()-1;
            rect = max(rect, width*heights[ind]);
        }

        st.push(i);
    }

    return rect;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int rect_height = largestRectangleArea(arr);
    cout << rect_height;


    
    return 0;
}