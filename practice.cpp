#include <bits/stdc++.h>
using namespace std;


void helper(int num, int target, vector<int> digits, int &val){
    cout << num << ' ' << val << endl;
    if (num > target) return ;

    val++;
    for (int i=0; i<digits.size(); i++){
        int newNum = num*10 + digits[i];
        helper(newNum, target, digits, val);
    }
}

int solve(int num, int target, vector<int>& digits){
	if (num > target) return 0;

	int n = digits.size(), val = 1;
	for (int i=0; i<n; i++) {
        if (num == 0 && digits[i] == 0) continue;  

		int newNum = num*10 + digits[i];
		val += solve(newNum, target, digits);
        cout << newNum << ' ' << val << endl;
	}

	return val;
}

int possibleNumbers(int n, int target, vector<int>& digits) {
    // int ans = 0;
    // helper(0, target, digits, ans);
    // cout << endl;
    
    int ans = solve(0, target, digits);

	return ans-1;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, target;
    cin >> n >> target;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    int ans = possibleNumbers(n, target, arr);
    cout << ans;
    

    
    
    return 0;
}