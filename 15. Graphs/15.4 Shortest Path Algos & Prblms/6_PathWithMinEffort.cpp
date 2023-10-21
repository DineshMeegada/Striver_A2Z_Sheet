#include <bits/stdc++.h>
using namespace std;

int MinimumEffort(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    vis[0][0] = 0;
    
    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>> > pq;
    pq.push({0, {0, 0}});

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};
    while (!pq.empty()) {
        auto iter = pq.top();
        int eff = iter.first;
        int row = iter.second.first;
        int col = iter.second.second;
        pq.pop();

        if (eff >= vis[n-1][m-1]) break;

        for (int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int diff = abs(heights[row][col] - heights[nrow][ncol]);
                if (max(diff, eff) < vis[nrow][ncol]){
                    vis[nrow][ncol] = max(diff, eff);
                    pq.push({vis[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    }

    return vis[n-1][m-1];

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> heights[i][j];
    }

    int effort = MinimumEffort(heights);
    cout << effort;
    
    return 0;
}