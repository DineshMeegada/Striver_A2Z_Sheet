#include <bits/stdc++.h>
using namespace std;

// Using DSU
class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return ;
        if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = parent[ulp_u];
        } else if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = parent[ulp_v];
        } else {
            parent[ulp_v] = parent[ulp_u];
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    bool isValid(int nrow, int ncol, int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector< pair<int, pair<int,int>> > positions;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                positions.push_back({grid[i][j], {i, j}});
            }
        }

        sort(positions.begin(), positions.end());
        DisjointSet ds(n*n);
        for (auto it: positions){
            int elev = it.first;
            int row = it.second.first;
            int col = it.second.second;

            int pos = row*n + col;

            vector<vector<int>> dinds = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            for (auto ind: dinds){
                int nrow = row + ind[0];
                int ncol = col + ind[1];

                if (isValid(nrow, ncol, n) && 
                grid[nrow][ncol] < grid[row][col]){
                    int curPos = nrow*n + ncol;
                    ds.unionByRank(pos, curPos);
                }
            }

            if (ds.findUPar(0) == ds.findUPar(n*n - 1)) return elev;
        }

        return -1;
    }
};


// Using Priority Queue
class Solution {
public:
    bool isValid(int nrow, int ncol, int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue< pair<int, pair<int,int>>, 
        vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>> > pq;

        pq.push({grid[0][0], {0,0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int ans = grid[0][0];
        while (!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int val = cur.first;
            int row = cur.second.first;
            int col = cur.second.second;

            ans = max(ans, val);
            if (row==n-1 && col==n-1){
                return ans;
            }

            vector<int> drow = {0, 0, -1, 1};
            vector<int> dcol = {-1, 1, 0, 0};

            for (int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (isValid(nrow, ncol, n) && !vis[nrow][ncol]){
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return ans;

    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}