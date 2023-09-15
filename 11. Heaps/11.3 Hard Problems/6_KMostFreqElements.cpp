#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for (auto it: mp){
            pq.push({it.second, it.first});
            if (pq.size()>k) pq.pop();
        }

        vector<int> res;
        while (k--){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    
    return 0;
}