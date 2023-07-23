#include <bits/stdc++.h>
using namespace std;

pair<int, int> FirstAndLastBS(vector<int> arr, int n, int k) {
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

int countOccurences(vector<int> arr, int n, int k){
    pair<int, int> occurences = FirstAndLastBS(arr, n, k);

    if (occurences.first == -1) return 0;
    return (occurences.second - occurences.first + 1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i] ;

    int count = countOccurences(arr, n, k);
    cout << count;
    
    
    return 0;
}