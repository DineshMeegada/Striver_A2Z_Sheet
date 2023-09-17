#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size(), flag = 1;
    vector<vector<int>> ans;

    for (int i=0; i<n; i++) {
        vector<int> curr = intervals[i];
        if (curr[1] > newInterval[0] && flag) {
            int low = min(newInterval[0], curr[0]);
            ans.push_back({low, newInterval[1]});
            flag = 0;
        }
        
        if (!ans.empty() && ans.back()[1] > curr[0]) ans.back()[1] = max(ans.back()[1], curr[1]);
        else ans.push_back(curr);
    }
    if (flag) ans.push_back(newInterval);

    return ans;
}

vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval) {
    vector<vector<int>> ans;
    int i = 0;

    while (i<n && intervals[i][1]<newInterval[0]) ans.push_back(intervals[i++]);
    while (i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while (i<n) ans.push_back(intervals[i++]);

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    vector<int> newInterval(2);

    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) cin >> intervals[i][j] ;
    }

    for (int i=0; i<2; i++) cin >> newInterval[i] ;

    vector<vector<int>> res = addInterval(intervals, n, newInterval);
    for (auto inter: res) {
        for (auto it: inter) cout << it << ' ' ;
        cout << endl;
    }

    
    return 0;
}