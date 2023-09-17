#include <bits/stdc++.h>
using namespace std;

int minimumReschedules(int n, vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    int prevEnd = intervals[0][1];
    int res = 0;
    for (int i=1; i<n; i++) {
        int start = intervals[i][0], end = intervals[i][1];
        if (start >= prevEnd) prevEnd = end;
        else {
            prevEnd = min(prevEnd, end);
            res++;
        }
    }

    return res;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1] ;

    cout << minimumReschedules(n, arr);
    
    
    
    
    return 0;
}