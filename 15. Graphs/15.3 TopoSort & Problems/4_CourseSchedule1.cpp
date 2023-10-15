#include <bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>>& prereq) {
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

    int cnt = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it: adj[node]){
            inDegree[it]--;
            if (inDegree[it]==0) q.push(it);
        }
    }

    return cnt==n;

}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    
    return 0;
}