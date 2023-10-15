#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int n, vector<int> adj[]) {

    vector<int> inDegree(n, 0);
    for (int i=0; i<n; i++) {
        for (auto it: adj[i]) {
          inDegree[it]++;
        }
    }
    
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (inDegree[i]==0) q.push(i);
    }
    
    int cnt = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;
        
        for (auto it: adj[curr]) {
            inDegree[it]--;
            if (inDegree[it]==0) q.push(it);
        }
    }
    
    return cnt!=n;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m ;
    cin >> n >> m ;

    vector<int> adj[n];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(n, adj);
    
    
    return 0;
}