#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for (int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if (parent[node]==node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return ;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int nrow, int ncol, int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);
        vector<pair<int,int>> zeroes;

        vector<int> drow = {0, 0, -1, 1};
        vector<int> dcol = {-1, 1, 0, 0};
        for (int row=0; row<n; row++){
            for (int col=0; col<n; col++){
                if (grid[row][col] == 0) {
                    zeroes.push_back({row, col});
                    continue;
                }
                for (int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(isValid(nrow, ncol, n)){
                        if (grid[nrow][ncol] == 1){
                            int curNode = row*n + col;
                            int adjNode = nrow*n + ncol;
                            ds.unionBySize(curNode, adjNode);
                        }
                    }
                }
            }
        }

        if (zeroes.empty()) return n*n;

        int ans = 1;
        for (auto it: zeroes){
            int row = it.first;
            int col = it.second;

            unordered_set<int> comps;
            for (int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (isValid(nrow, ncol, n) && grid[nrow][ncol]==1) {
                    int nodeNo = nrow*n + ncol;
                    int par = ds.findUPar(nodeNo);
                    comps.insert(par);
                }                    
            }

            int curSize = 0;
            for (auto it: comps){
                curSize += ds.size[it];
            }

            ans = max(ans, curSize+1);
        }

        return ans;
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}