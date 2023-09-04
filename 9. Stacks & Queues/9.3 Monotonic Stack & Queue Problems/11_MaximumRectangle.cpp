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

int maximalRectangle(vector<vector<char>>& mat) {
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++){
            matrix[i][j] = mat[i][j]-'0';
        }
    }

    for (int i=1; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j]) matrix[i][j] += matrix[i-1][j];
        }
    }

    int res = 0;
    for (int i=0; i<m; i++) {
        int curr = largestRectangleArea(matrix[i]);
        res = max(res, curr);
    }

    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    


    
    return 0;
}