#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& prereq) {
    vector<int> adj[n];
    for (auto it: prereq) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
    }

    vector<int> inDegree(n, 0);
    for (int i=0; i<n; i++) {
        for (auto it: adj[i]) inDegree[it]++;
    }

    queue<int> q;
    for (int i=0; i<n; i++) {
        if (inDegree[i]==0) q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto it: adj[node]){
            inDegree[it]--;
            if (inDegree[it]==0) q.push(it);
        }
    }

    if (res.size()!=n) return {};
    reverse(res.begin(), res.end());
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}