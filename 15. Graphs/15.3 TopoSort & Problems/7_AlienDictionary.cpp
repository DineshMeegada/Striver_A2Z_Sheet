#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void findDiff(string str1, string str2, vector<int> adj[]){
    int i = 0;
    int m = str1.size(), n = str2.size();
    
    while (i<m && i<n) {
        if (str1[i]!=str2[i]) {
            int num1 = str1[i]-'a';
            int num2 = str2[i]-'a';
            
            adj[num1].push_back(num2);
            break;
        }
        i++;
    }
}

string topoSort(vector<int> adj[], int k) {
    vector<int> inDegree(k, 0);
    for (int i=0; i<k; i++) {
        for (auto it: adj[i]) {
            inDegree[it]++;
        }
    }
    
    queue<int> q;
    for (int i=0; i<k; i++) {
        if (inDegree[i]==0) q.push(i);
    }
    
    string res = "";
    while (!q.empty()) {
        int node = q.front();
        res += 'a'+node;
        q.pop();
        
        for (auto it: adj[node]) {
            inDegree[it]--;
            if (inDegree[it]==0) {
                q.push(it);
            }
        }
    }
    
    return res;
    
}

string getAlienLanguage(vector<string> &dict, int k) {
    int n = dict.size();
    vector<int> adj[k];
    
    for (int i=0; i<n-1; i++) {
        findDiff(dict[i], dict[i+1], adj);
        
    }

    for (auto nodes: adj){
        for (auto it: nodes) cout << it << ' ';
        cout <<endl;
    }
    
    string res = topoSort(adj, k);
    return res;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    

    int n , k ;
    cin >> n >> k;

    vector<string> dict(n);
    for (int i=0; i<n; i++) {
        cin >> dict[i];
    }

    cout << getAlienLanguage(dict, k);
    
    
    
    return 0;
}