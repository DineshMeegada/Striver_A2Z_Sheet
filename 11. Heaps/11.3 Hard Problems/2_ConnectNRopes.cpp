#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int minCost(vector<int> arr, int n){
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i=0; i<n; i++) {
		pq.push(arr[i]);
	}

	int res = 0;
	while (!pq.empty()){
		int a = pq.top();
		pq.pop();
		
		int b = pq.top();
		pq.pop();

		int curr = a+b;
		res += curr;

		if (!pq.empty()) pq.push(curr);
	}

	return res;
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int cost = minCost(arr, n);
    cout << cost ;
    
    return 0;
}