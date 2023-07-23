#include <bits/stdc++.h>
using namespace std;

int KthElement(vector<int> arr1, vector<int> arr2, int m, int n, int k){
    if (m > n) return (KthElement(arr2, arr1, n, m, k));
    
    int low = 0, high = m;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = cut1==0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2<=0 || cut2>=n ? cut2<=0 ? INT_MIN : arr2[n-1] : arr2[cut2-1];
        int r1 = cut1==m ? INT_MAX : arr1[cut1];
        int r2 = cut2<=0 || cut2>=n ? cut2<=0 ? arr2[0] : INT_MAX : arr2[cut2];

        cout << cut1 << "  " << cut2 << endl;

        cout << l1 << " " << l2 << "    " << r1 << " " << r1 << " " << endl;

        if (l1<=r2 && l2<=r1) return (max(l1, l2));
        else if (l1>r2) high = cut1 - 1;
        else low = cut1 + 1;
    }

    return 0;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n, k;
    cin >> m >> n >> k;
    
    vector<int> arr1(m);
    for (int i=0; i<m; i++) cin >> arr1[i] ;

    vector<int> arr2(n);
    for (int i=0; i<n; i++) cin >> arr2[i] ; 

    int ele = KthElement(arr2, arr1, n, m, k);
    cout << ele ;
    
    
    return 0;
}