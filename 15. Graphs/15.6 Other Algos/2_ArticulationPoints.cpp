#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&vis, vector<int> adj[], 
    int tin[], int low[], vector<int> &mark){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]) {
            if (it == parent) continue;
            if (!vis[it]){
                dfs(it, node, vis, adj, tin, low, mark);
                low[node] = min(low[it], low[node]);
                
                if (low[it]>=tin[node] && parent!=-1) mark[node] = 1;
                child++;
            }else {
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if (child>1 && parent==-1) mark[node] = 1;
    }
    
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> vis(v, 0), mark(v, 0);
        int tin[v];
        int low[v];
        
        for (int i=0; i<v; i++){
            if (!vis[i]){
                dfs(i, -1, vis, adj, tin, low, mark);
            }
        }
        
        vector<int> ans;
        for (int i=0; i<v; i++){
            if (mark[i] == 1) ans.push_back(i);
        }
        
        if (ans.empty()) return {-1};
        return ans;
        
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}