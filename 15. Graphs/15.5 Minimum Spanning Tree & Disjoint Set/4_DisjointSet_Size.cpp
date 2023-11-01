#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> size, parent;

public :

    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);

        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) return node;

        int par = findParent(parent[node]);
        parent[node] = par;

        return par;
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            size[ulp_u] += size[ulp_v];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }

};



int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
       
    
    
    return 0;
}