#include <bits/stdc++.h>
using namespace std;

float medianOfSortedArrays(vector<int> arr1, vector<int> arr2, int m,  int n){
    int low = 0, high = m, medianPos = (low + high + 1)/2;

    if (m<n) return (medianOfSortedArrays(arr2, arr1, n, m));

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = medianPos - cut1;

        int l1 = cut1==0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2==0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1==m ? INT_MAX : arr1[cut1];
        int r2 = cut2==n ? INT_MAX : arr2[cut2];

        if (l1<=r2 && l2<=r1) {
            if ((m+n)%2 == 0){
                return ((max(l1, l2) + min(r1, r2))/2.0);
            } else return (max(l1, l2));
        }else if (l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }

    return 0.0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;
    
    vector<int> arr1(m);
    for (int i=0; i<m; i++) cin >> arr1[i] ;
    
    vector<int> arr2(n);
    for (int i=0; i<n; i++) cin >> arr2[i] ;

    float median = medianOfSortedArrays(arr1, arr2, m, n);

    return 0;
}