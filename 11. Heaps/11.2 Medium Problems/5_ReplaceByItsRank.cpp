#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &nums, int n) {
    vector<int> arr(nums);

    vector<int> ans;
    unordered_map<int, int> ranks;
    sort(arr.begin(), arr.end());

    int rank = 1;
    for(int i=0; i<n; i++) {
        if (i==n-1 || arr[i]!=arr[i+1]){
            ranks[arr[i]] = rank++;
        }
    }

    for (int i=0; i<n; i++) {
        int curr_rank = ranks[nums[i]];
        ans.push_back(curr_rank);
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> rankVec = replaceWithRank(arr, n);
    for (auto it: rankVec) cout << it << ' ';
    
    
    return 0;
}