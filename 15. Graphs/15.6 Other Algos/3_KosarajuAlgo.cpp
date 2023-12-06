// Strongly Connected Components
#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for (auto it: adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    
    st.push(node);
}

void dfs3(int node, vector<int> adjT[], vector<int> &vis, vector<int> &comps){
    vis[node] = 1;
    comps.push_back(node);
    for (auto it: adjT[node]){
        if (!vis[it]){
            dfs3(it, adjT, vis, comps);
        }
    }
}

int kosaraju(int v, vector<vector<int>>& adj, vector<vector<int>> &scc_comps) {
    vector<int> vis(v, 0);
    stack<int> st;
    
    // DFS for filling the stack
    for (int i=0; i<v; i++){
        if (!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    
    // Transpose the graph
    vector<int> adjT[v];
    for (int i=0; i<v; i++){
        vis[i] = 0;
        for (auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }
    
    // DFS again
    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            vector<int> comps;
            dfs3(node, adjT, vis, comps);
            scc_comps.push_back(comps);
        }
    }
    
    return scc;
    
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<vector<int>> scc_comps;
    int scc = kosaraju(v, adj, scc_comps);

    cout << scc << endl;
    for (auto iter: scc_comps){
        for (auto it: iter) cout << it << ' ';
        cout <<endl;
    }


    
    
    
    return 0;
}