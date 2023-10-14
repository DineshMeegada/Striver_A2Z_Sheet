#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    
    for (auto it: adj[node]) {
        if (!vis[it]) dfs(it, vis, adj, st);
    }
    
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int e, int v) {
    vector<int> adj[v];
    for(auto it: graph){
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(v, 0);
    stack<int> st;
    
    for(int i=0; i<v; i++) {
        if (!vis[i]) dfs(i, vis, adj, st);
    }
    
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}