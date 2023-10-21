#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    if (start==end) return 0;
    int mod = 1e5;
    
    queue<pair<int,int>> q;
    q.push({start, 0});
    
    vector<int> dist(1e5, 1e9);
    dist[start] = 0;
    
    while (!q.empty()) {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        
        for (auto it: arr){
            int num = (it*node) % mod;
            if(1+dis<dist[num]){
                dist[num] = 1+dis;
                if (num==end) return dist[num];
                q.push({num, dist[num]});
            }
        }
    }
    
    return -1;
    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int start, end;
    cin >> start >> end;

    cout << minimumMultiplications(arr, start, end);
    
    
    return 0;
}