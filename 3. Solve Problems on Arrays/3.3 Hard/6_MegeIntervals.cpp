#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
	sort(intervals.begin(), intervals.end());
    vector<vector<int>> mergedIntervals;

    if(intervals.size() == 0) return mergedIntervals;
    int left = intervals[0][0], right = intervals[0][1];

    for (int i=1; i<intervals.size(); i++){
        if (intervals[i][0] <= right){
            right = max(right, intervals[i][1]);
        }else {
            mergedIntervals.push_back({left, right});
            left = intervals[i][0], right = intervals[i][1];
        }
    }
    mergedIntervals.push_back({left, right});

    return mergedIntervals;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(2));
	for (int i=0; i<n; i++){
		for (int j=0; j<2; j++) cin >> arr[i][j];
	}
	
	vector<vector<int>> resIntervals = mergeIntervals(arr);
	for(int i=0; i<n; i++){
		for (int j=0; j<2; j++) cout << resIntervals[i][j] << " ";
		cout << endl;
	}



}


