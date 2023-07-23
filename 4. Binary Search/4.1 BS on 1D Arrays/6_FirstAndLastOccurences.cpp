#include <bits/stdc++.h>
using namespace std;

// using lower bound and upper bound concepts
vector<int> FirstAndLastOccurences(vector<int> arr, int n, int k){
    int first = n, last = n;
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= k) {
            first = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > k) {
            last = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    if (first == n || arr[first] != k) return {-1, -1};
    return {first, last - 1};
}

// using pure binary search
vector<int> FirstAndLastBS(vector<int> arr, int n, int k) {
    int first = -1, last = -1;
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] > k) high = mid - 1;
        else low = mid + 1;
    }

    low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] > k) high = mid - 1;
        else low = mid + 1;
    }

    return {first, last};
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;
    
    vector<int> positions = FirstAndLastBS(arr, n, k);

    cout << positions[0] << " " << positions[1];
    
    
    return 0;
}