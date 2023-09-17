#include <bits/stdc++.h>
using namespace std;

int candyGeneral(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> temp (n, 1);

    for (int i=1; i<n; i++) {
        if (ratings[i]>ratings[i-1]) temp[i] = temp[i-1]+1;
    }

    for (int i=n-2; i>=0; i--) {
        if (ratings[i]>ratings[i+1] && temp[i]<=temp[i+1]) temp[i] = temp[i+1]+1;
    }

    int res = 0;
    for (auto it: temp) {
        cout << it << ' ';
        res += it ;
    }

    return res;
}

int candy(vector<int> &ratings) {
    int n = ratings.size();
    int ans = n, i = 1;

    while (i<n){
        if (ratings[i] == ratings[i-1]) {
            i++;
            continue;
        }
        
        int peak = 0;
        while (i<n && ratings[i]>ratings[i-1]){
            peak++;
            ans += peak;
            i++;
        }

        int deep = 0;
        while (i<n && ratings[i]<ratings[i-1]){
            deep++;
            ans += deep;
            i++;
        }

        ans -= min(peak, deep);
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
    
    int total_candies = candy(arr);
    cout << endl << total_candies << endl;

    
    return 0;
}