#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for (int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;
        if (size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());

        unordered_map<string, int> mp;
        for (int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if (mp.find(mail) != mp.end()){
                    int par = mp[mail];
                    ds.unionBySize(i, par);
                } else {
                    mp[mail] = i;
                }
            }
        }

        vector<string> arr[n];
        for (auto it: mp){
            int par = ds.findUPar(it.second);
            arr[par].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (int i=0; i<n; i++){
            if (arr[i].empty()) continue;
            sort(arr[i].begin(), arr[i].end());

            vector<string> curr = {accounts[i][0]};
            for(auto it: arr[i]) curr.push_back(it);

            ans.push_back(curr);
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    
    return 0;
}