#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it: adj[curr]){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push({it, curr});
                }else if (parent != it) return true;
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for (int i=0; i<V; i++) {
            if (!vis[i]){
                if (bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}