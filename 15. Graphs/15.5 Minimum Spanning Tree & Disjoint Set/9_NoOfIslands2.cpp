#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        
        parent.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if (parent[node] == node) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return ;
        if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    
};

class Solution {
private:
    bool isValid(int nrow, int ncol, int n, int m) {
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        
        int cnt = 0;
        vector<int> ans;
        
        for (auto it: operators){
            int row = it[0];
            int col = it[1];
            
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            vector<int> drow = {-1, 1, 0, 0};
            vector<int> dcol = {0, 0, -1, 1};
            
            int curNode = row*m + col;
            
            for (int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if (isValid(nrow, ncol, n, m)){
                    if (vis[nrow][ncol]== 1){
                        int adjNode = nrow*m + ncol;
                        
                        if (ds.findUPar(curNode) != ds.findUPar(adjNode)){
                            cnt--;
                            ds.unionByRank(curNode, adjNode);
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}