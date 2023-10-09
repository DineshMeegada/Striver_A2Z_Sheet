#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);
    vis[0] = 1;
    
    queue<int> q;
    q.push(0);
    
    vector<int> bfs;
    while (!q.empty()) {
        int curr = q.front();
        bfs.push_back(curr);
        q.pop();
        
        for (auto it: adj[curr]) {
            if (vis[it] == 0){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    
    return bfs;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    
    
    
    return 0;
}