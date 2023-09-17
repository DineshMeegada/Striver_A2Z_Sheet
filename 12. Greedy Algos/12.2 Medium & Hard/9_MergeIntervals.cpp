#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    int i = 1;
    while (i<n) {
        while (i<n && intervals[i][0]<=ans.back()[1]){
            ans.back()[0] = min(ans.back()[0],intervals[i][0]);
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            i++;
        }

        if(i<n) ans.push_back(intervals[i++]);
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i=0; i<n; i++) cin >> intervals[i][0];
    for (int i=0; i<n; i++) cin >> intervals[i][1] ;

    vector<vector<int>> res = mergeIntervals(intervals);
    for (auto it: intervals) cout << it[0] << ' ' << it[1] << endl;
    
    return 0;
}