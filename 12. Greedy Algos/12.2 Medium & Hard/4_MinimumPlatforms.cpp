#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int i = 0, j = 0;
    int count = 0, ans = 0;
    while (i<n) {
        if (arr[i]<=dep[j]){
            count++;
            ans = max(ans, count);
            i++;
        }else if (arr[i]>dep[j]) {
            count--;
            j++;
        }
    }

    return ans;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    int arr1[n];
    for (int i=0; i<n; i++) cin >> arr1[i] ;
    
    int arr2[n];
    for (int i=0; i<n; i++) cin >> arr2[i] ;
    
    cout << calculateMinPatforms(arr1, arr2, n);
    
    
    return 0;
}