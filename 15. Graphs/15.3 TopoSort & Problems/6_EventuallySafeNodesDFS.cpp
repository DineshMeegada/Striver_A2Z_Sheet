#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, 
vector<int> &check) {
    vis[node] = 1;
    path[node] = 1;
    check[node] = 0;

    for (auto it: adj[node]) {
        if (!vis[it] && dfs(it, adj, vis, path, check)) return true;
        else if (path[it]) return true;
    }
    
    check[node] = 1;
    path[node] = 0;
    return false;
}

//  Using DFS of finding cycle in DAG
vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
    vector<int> vis(v, 0), path(v, 0), check(v, 0);
    vector<int> safeNodes;

    for (int i=0; i<v; i++) {
        if (!vis[i]) dfs(i, adj, vis, path, check);
    }
    
    for (int i=0; i<v; i++) {
        if (check[i]) safeNodes.push_back(i); 
    }

    return safeNodes;
}


// Using Topological Sort BFS
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> adjRev[n];
    for (int i=0; i<n; i++) {
        for (auto it: graph[i]){
            adjRev[it].push_back(i);
        }
    }

    vector<int> inDegree(n);
    for (int i=0; i<n; i++) {
        for (auto it: adjRev[i]) inDegree[it]++;
    }

    queue<int> q;
    for (int i=0; i<n; i++) {
        if (inDegree[i]==0) q.push(i);
        if (inDegree[i]==0) cout << i << ' ';
    }

    vector<int> res;
    while (!q.empty()) {
        int node = q.front();
        res.push_back(node);
        q.pop();

        for (auto it: adjRev[node]){
            inDegree[it]--;
            if(inDegree[it]==0) {
                q.push(it);
            } 
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}