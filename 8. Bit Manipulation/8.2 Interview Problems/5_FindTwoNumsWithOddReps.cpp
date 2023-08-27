#include <bits/stdc++.h>
using namespace std;

vector<int> twoOddNum(vector<int> arr){
    int xor1 = 0;
    for (auto it: arr) xor1 = xor1^it;

    int ind = 0;
    while (xor1){
        int temp = xor1 & 1;
        if (temp != 0) break;
        ind++;
        xor1 = xor1 >> 1;
    }

    int mask = 1 << ind;
    int a = 0, b = 0;
    for (auto it: arr) {
        int temp = mask&it ;
        if (!temp) a = a^it;
        else b = b^it;
    }

    int maxi = max(a, b);
    int mini = min(a, b);

    return {maxi, mini};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> res = twoOddNum(arr);
    for (auto it: res) cout << it << ' ';
    
    return 0;
}