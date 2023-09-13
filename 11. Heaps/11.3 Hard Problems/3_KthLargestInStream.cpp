#include <bits/stdc++.h>
using namespace std;

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    Kthlargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>size) pq.pop();

        return pq.top();
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    
    
    return 0;
}